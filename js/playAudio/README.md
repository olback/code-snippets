# playAudio.js

## Docs

addAudio(_string/int_ id, _string_ source, _int_ volume);  
Example: `addAudio("audio1", "https://example.com/your_audiofile.mp3", 50);`

playAudio(_string/int_ id);  
Example: `playAudio("audio1");`

pauseAudio(_string/int_ id);  
Example: `pauseAudio("audio1");`

volumeAudio(_string/int_ id, _int_ volume);  
Example: `volumeAudio("audio1", 20);` 

stopAudio(_string/int_ id);  
Example: `stopAudio("audio1");`

An ID can be either a string or a integer.  
Volume is enterd in percent without the '%'.  
HTML5 supports most audio formats you can think of. Such as mp3, wav and ogg.  
For a complete reference, see [this article on MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Supported_media_formats).
