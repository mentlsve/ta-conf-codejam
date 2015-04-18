    $('#thumbsup').click(function(){ 
         $.ajax({ 
             type: "PUT",
             contentType: "text/plain",
			 data: "thumbsup",
             url: "http://52.28.31.152:3000/resources/vote",
             success: function(data){        
                
             }
         });
    });
	
	    $('#thumbsdown').click(function(){ 
         $.ajax({ 
             type: "PUT",
             contentType: "text/plain",
			 data: "thumbsdown",
             url: "http://52.28.31.152:3000/resources/vote",
             success: function(data){        
             
             }
         });
    });

