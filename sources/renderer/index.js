const {app} = require('electron');

let content = document.querySelector('.content');

let render = {
    start: () => {
        content.style.width = '100%';
        content.style.height = '100%';
        content.style.position = 'absolute';
        content.style.top = 0;
        content.style.left = 0;
        content.style.overflow = 'hidden';
        content.style.backgroundColor = '#000';
    }
};

module.exports = render;