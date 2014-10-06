  function _$call(method,params,callback){
        for(key in params){
            params[key] = JSON.stringify(params[key])
        }
        params.method = method;
        $.ajax({
            type    : "GET",
            url     : "http://127.0.0.1:9999/do",
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
