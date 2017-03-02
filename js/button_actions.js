function loadExample(file) {
	var xmlhttp = new XMLHttpRequest();
	var editor = getEditor();
	
	xmlhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
			editor.setValue(this.responseText);
		}
	};
	
	switch (file) {
		case 'new':
		default:
			xmlhttp.open('GET', 'cube_files/empty_sketch.ino', true);
			break;
			
		case 'ex1':
			xmlhttp.open('GET', 'cube_files/blink.ino', true);
			break;
		
		case 'ex2':
			xmlhttp.open('GET', 'cube_files/random_led.ino', true);
			break;
			
		case 'ex3':
			xmlhttp.open('GET', 'cube_files/random_led2.ino', true);
			break;
			
		case 'ex4':
			xmlhttp.open('GET', 'cube_files/fill_cube.ino', true);
			break;
			
		case 'ex5':
			xmlhttp.open('GET', 'cube_files/moving_plane.ino', true);
			break;
			
		case 'ex6':
			xmlhttp.open('GET', 'cube_files/flags.ino', true);
			break;
			
		case 'ex7':
			xmlhttp.open('GET', 'cube_files/rainbow.ino', true);
			break;
			
		case 'ex8':
			xmlhttp.open('GET', 'cube_files/morse.ino', true);
			break;
			
		case 'ex9':
			xmlhttp.open('GET', 'cube_files/spiral.ino', true);
			break;
	}
	
	xmlhttp.send();
}