define(['lang/BaseObject', 'sprites/Sprite'], function(BaseObject, Sprite) {
    "use strict";
    var _cache = {};
    
    /**
     * @returns {void}|{image}
     */
    return function(id, resource, onload, onerror) {
        if (id && resource) {
            _cache[id] = new Image();
            _cache[id].onload = function() {
                onload(arguments);
                _cache[id].onload = null;
            };
            _cache[id].onerror = function() {
                onerror(arguments);
                _cache[id].onerror = null;
            };
            _cache[id].src = resource;
        }
        if (_cache[id]) {
            return _cache[id];
        }
    };
});