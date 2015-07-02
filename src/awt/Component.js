/**
 * @module awt/Component
 */
define(['lang/BaseObject'], function(BaseObject) {
	"use strict";
	return BaseObject.extend({
		constructor: function() {
			this._x = 0;
			this._y = 0;
		}
	});
});