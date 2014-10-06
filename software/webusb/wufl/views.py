from django.template import Template, Context
from django.http import HttpResponse
#from django.utils import simplejson
import json as simplejson
from django.http import HttpResponseRedirect
from django.shortcuts import render
import threading
import traceback
from func import *
from common import js_handler
import os.path
import datetime 
  
htmldir = os.path.join(os.path.dirname(__file__), 'html').replace('\\','/')
## hello test simplejson
def hello(request):
    a = request.REQUEST['a'] 
    b = request.REQUEST['b']
    
    a = simplejson.loads(a)
    b = simplejson.loads(b)
    ret = 0
    if a!=None and b!=None:
        ret = a+b
    jsret = simplejson.dumps(ret) 
    return HttpResponse(jsret)
def index(request):
    p = 'index'
    if 'p' in request.GET:
        p = request.GET['p']
    furl= os.path.join(htmldir,p).replace('\\','/')+".html"
    fp = open(furl)
    t = Template(fp.read())
    fp.close()
    now = datetime.datetime.now()  
    html=t.render(Context({'current_date': now}))
    return HttpResponse(html)

## js api handler

rk = threading.Lock()
wk = threading.Lock()
rc = 0

def readInc():
    global rc,rk,wk
    rk.acquire()
    rc = rc+1
    if rc==1:
        wk.acquire()
    rk.release()

def readDec():
    global rc,rk,wk
    rk.acquire()
    rc = rc-1
    if rc==0:
        wk.release()
    rk.release()


def _do(request,transfer_handler):
    params = dict()
    ret = None
    try:
        for k,v in request.GET.items():
            params[k] = v
        sm = params.pop('method')
        m = get_func(sm)
        assert(transfer_handler.parse(m[1],m[2],params))
        readInc()
        try:
            ret = call_func(sm,params)
        except:
            traceback.print_exc()
        readDec()
    except:
        traceback.print_exc()
    try:
        ret = transfer_handler.encode(ret)
    except:
        ret = transfer_handler.encode(None)
        traceback.print_exc()
    return ret
    
def do(request):
    jsret = _do(request,js_handler)
    return HttpResponse(jsret)
    
