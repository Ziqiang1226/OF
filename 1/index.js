var fs = require('fs');
var cheerio = require('cheerio');
var request = require('request');
var serEn = "http://www.searchsystem.co";

var imgUrls = []
function requ (){

  request(serEn, function (error, response, body) {
    if (!error && response.statusCode == 200) {
      fs.writeFileSync('serEn.html', body);
    }
    else {console.error('request failed')}
  });
}
requ();

setTimeout(
function downloaddd(){
  var dataset = fs.readFileSync('/Users/heziqiang/1/serEn.html','utf8');
  var $ = cheerio.load(dataset);

  $("img").each(function(i,elem){
    if($(elem).attr("src").match(/.jpg/) || $(elem).attr("src").match(/.png/)   ){
      imgUrls.push($(elem).attr("src"));
    }
  });

  var folder = 'public/images/';
  var download = function(uri, filename, callback){
    request.head(uri, function(err, res, body){
      console.log('content-type:', res.headers['content-type']);
      console.log('content-length:', res.headers['content-length']);

      request(uri).pipe(fs.createWriteStream(filename)).on('close', callback);
    });
  };



    for(var i = 0;i<imgUrls.length;i++){
      download(imgUrls[i], i+".jpg", function(){
        console.log('done');
      });
    }
}
, 5000);


//-----------------------------------------------------------

var express = require('express');
var app = express();
var fs = require('fs');


var mArray = [];

app.set('view engine', 'ejs');

app.use(express.static('public'));


for(i=0; i<8; i++){
	mArray[i] = "images/" + i + ".jpg";
}




app.get('/', function (req, res) {
    res.render(
        'index',
        // { title: 'Hey Hey Hey!', message: 'Yo Yo', imgUrl:'1.jpg'})
        { title: 'Hey Hey Hey!', message: 'Yo Yo', arr: mArray});

})


app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
})