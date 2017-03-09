/**
 * Script with some functions to perform the necessary actions in the interaction with the user.
 * 
 * @author: Sergio Roldan
 */


/**
 * Function that selects one from a set of local predefined example files and loads in into the editor
 * @param file	The desired file
 */
function loadExample(file) {
	
	// Object to handle file loads
	var xmlhttp = new XMLHttpRequest();
	
	// This event will be triggered once the file is loaded	
	xmlhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
			var editor = getEditor();
			editor.setValue(this.responseText);
		}
	};
	
	// Open the desired file
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


/**
 * Function that is triggered when the user wants to load a file using the 'input' html object
 * @param evt	The event of the 'input' object when it is changed (file selected)
 */
function onLoadFile(evt) {
    
	// Check API support
	if (window.File && window.FileReader && window.FileList && window.Blob) {
		// Get the last selected file
		var file = evt.target.files[0];
		if (file) {
			
			// Check the extension of the selected file
			var fileName = file.name;
			var fileExtension = fileName.split('.')[fileName.split('.').length - 1].toLowerCase();
			if (fileExtension != 'ino') {
				window.alert('The selected file must be a valid *.ino sketch!')
				return;
			} 
			
			// Read the file
			var fr = new FileReader();
			fr.onload = function(e) {
				var contents = e.target.result;
				var editor = getEditor();
				editor.setValue(contents);
				document.getElementById('editor-select').value = 'new';
			}
			
			fr.readAsText(file);
		}
	}
}

/**
 * Function that is triggered when the user wants to save the text in the code editor in a file
 */
function onSaveFile()
{
    var text = getEditor().getValue();
    var blob = new Blob([text], {type:'text/plain'});
    var fileName = 'CubeSketch.ino';

    var downloadLink = document.createElement("a");
    downloadLink.download = fileName;
    downloadLink.innerHTML = 'Download File';
    
	if (window.webkitURL != null) {
        downloadLink.href = window.webkitURL.createObjectURL(blob);
    } else  {
        downloadLink.href = window.URL.createObjectURL(blob);
        downloadLink.style.display = 'none';
        document.body.appendChild(downloadLink);
    }

    downloadLink.click();
}

  