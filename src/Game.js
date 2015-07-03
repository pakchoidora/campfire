/**
 * Game Application
 * @module Game
 */
define(['jquery', 'awt/Stage', 'awt/Circle', 'lang/BaseObject'], function($, Stage, Circle, BaseObject) {
    "use strict";
    /**
     * @private
     * @param {Event} evt
     */
    function handleKeyEvent(evt) {
        // TODO: Complete the function.
        switch(evt.keyCode) {
            default:
                break;
        }
    }

    /**
     * @param {string} key keyCode of keyboard key.
     * @param {function} callback
     * @returns {void}
     */
    function keyBind(key, callback) {
        // TODO: Complete the method.
    }

    return BaseObject.extend({
        /**
         * @type {Object}
         */
        __stage: {},

        /**
         * @type {Object}
         */
        _graphics: {},

        /**
         * milliseconds per frame last
         * @type {Number}
         */
        __speed: 30,

        /**
         * render the stage
         * @returns {void}
         */
        _render: function () {
            this._clear();
            this.__stage.update();
        },

        /**
         * init the game application.
         * @returns {void}
         */
        constructor: function () {
            $(window).on({
                keypress: function (evt) {
                    this.handleKeyEvent(evt);
                },
                contextmenu: function (evt) {
                    evt.preventDefault();
                }
            });
            $('div#content').append($('<div>').attr('id', 'stage'));
            this.__stage = new Stage('#stage');
            this._graphics = this.__stage.graphics();
            this.__circle = new Circle(this.__stage.width() / 2, this.__stage.height() / 2, 50);
            this.__circle.fillColor('#222');
            this.__circle_outer = new Circle(this.__stage.width() / 2, this.__stage.height() / 2, 70);
            this.__circle_outer.fillColor('lightgreen');
            this.__stage.add(this.__circle);
            this.__stage.add(this.__circle_outer);
            this._loop();
        },

        /**
         * Update Loop
         * @returns {void}
         */
        _loop: function () {
            this._render();
            setTimeout(this._loop.bind(this), this.__speed);
        },

        /**
         * pause the game.
         * @returns {void}
         */
        pause: function() {
            this._pause = true;
        },

        /**
         * resume the game when paused.
         * @returns {void}
         */
        resume: function() {
            this.__interval = setInterval(this.update.bind(this), this.__speed);
        },

        /**
         * clear the game stage
         * @returns {void}
         */
        _clear: function() {
            this.__stage.clear();
        },

        /**
         * set the game's preferences
         * @returns {void}
         */
        setting: function() {
            // TODO: Complete the function.
            keyBind();
        },
        
        /**
         * Show the game board.
         * @returns {void}
         */
        showGameBoard: function() {
            
        },
        
        handleKeyEvent: handleKeyEvent
    });
});