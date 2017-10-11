/*
 *  Play audio with simple functions in JavaScript
 *             2017 © olback.net
 */


const sounds = {};

function addAudio(id, path, volumeIn) {
    sounds[id] = new Audio(path);

    if(volumeIn !== undefined) {
        volume = volumeIn / 100;
        sounds[id].volume = volume;
    }

    return 1;
}

function playAudio(id) {
    sounds[id].play();
    return 1;
}

function stopAudio(id) {
    sounds[id].pause();
    sounds[id].currentTime = 0;
    return 1;
}

function pauseAudio(id) {
    sounds[id].pause();
    return 1;
}

function volumeAudio(id, volumeIn) {
    volume = volumeIn / 100;
    sounds[id].volume = volume;
    return 1;
}
