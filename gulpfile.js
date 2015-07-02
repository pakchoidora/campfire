var gulp = require('gulp');
var $ = require('gulp-load-plugins')();
var del = require('del');
var path = require('path');
var stylish = require('jshint-stylish');
var amdOptimize = require('amd-optimize');

var DIST = './dist/';
var FILTER = {
    res: 'view/res/**/*',
    html: 'view/html/**/*',
    less: 'view/less/**/*.less',
    js: 'src/**/*.js'
};

gulp.task('clean', function(callback) {
    return del([DIST], callback);
});

function _uglify(path) {
    return gulp.src(path)
        .pipe($.jshint())
        .pipe($.jshint.reporter(stylish))
        .pipe($.uglify({
            mangle: true,
            reporter: 'min'
        }))
        .pipe(gulp.dest(DIST + 'js'));
}

function _less(path) {
    if (!Array.isArray(path)) {
        path = [path];
    }
    return gulp.src(path)
        .pipe($.less({
            paths: [path.join(__dirname, 'less', 'includes')]
        }))
        .pipe($.cssmin())
        .pipe(gulp.dest(DIST + 'css'));
}

gulp.task('uglify', function() {
    return _uglify(FILTER['js']);
});

gulp.task('less', function() {
    return _less(FILTER['less']);
});

gulp.task('copy', function() {
    return gulp.src([FILTER['res'], FILTER['html']])
        .pipe($.copy(DIST, {prefix: 2}));
});

gulp.task('default', ['copy', 'uglify', 'less'], function() {

    gulp.watch(FILTER['js'], function(event) {
        return _uglify(event.path);
    });

    gulp.watch(FILTER['less'], function(event) {
        return _less(event.path);
    });
});