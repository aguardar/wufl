from django.conf.urls import patterns, include, url
from views import *
import wufl.settings

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('',
    url(r'^static/(?P<path>.*)$','django.views.static.serve',{ 'document_root':settings.STATIC_ROOT }),
    url(r'^hello/$', hello),
    url(r'^do$',do),
    url(r'^$',index),
    # Examples:
    # url(r'^$', 'wf4hf.views.home', name='home'),
    # url(r'^wf4hf/', include('wf4hf.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
)
