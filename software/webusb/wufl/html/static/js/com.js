var welcomemsg="welcome";

console.debug(welcomemsg);

var hostaddr={};
hostaddr.address="127.0.0.1";
hostaddr.port="9999";
  function _$jsonpcall(method,params,callback){
        var ret;
        for(key in params){
            params[key] = JSON.stringify(params[key])
        }
        params.method = method;
        // params.callback = '?';
		uri="http://"+hostaddr.address+":"+hostaddr.port+"/do";
        var ret;
        $.ajax({
            type    : "GET",
            url     : uri,
            async   : true,
            data    : params,
            dataType :"jsonp",
            crossDomain: true,
            success : function(data){
                if(callback!=undefined&&callback!=null){
                    callback(data);
                }
                console.debug('ret',data);
            },
            error   : function(xmlHttp,textStatus){
                //alert('error');
            }
        });
    }
var com={
    init:function(){}, 

    openled:function(callback){
	  callback=print;
      var params = {};
        return _$call('openled',params,callback);
    },
	print:function(data){
	  console.debug(data[0].retstr);
    }
	,
	sethostaddress:function(addr,port,callback){
	var params = {};
       hostaddr.address=addr;
	   hostaddr.port=port;
	   _$call = _$jsonpcall;
        return _$call('test',params,callback);
    }

};
function hello(data){
console.debug(data.retstr);
}
com.init();
