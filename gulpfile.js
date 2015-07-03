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

function _uglify(options) {
    var release = options && options['release'];
    return gulp.src(FILTER['js'])
        .pipe($.if(options && options['newer'], $.newer(DIST + 'js')))
        .pipe($.if(!release, $.sourcemaps.init()))
        .pipe($.jshint())
        .pipe($.jshint.reporter(stylish))
        .pipe($.uglify({
            mangle: true
        }))
        .pipe($.if(!release, $.sourcemaps.write('./')))
        .pipe(gulp.dest(DIST + 'js'));
}

function _less(options) {
    var path = Array.isArray(FILTER['less']) ? FILTER['less'] : [FILTER['less']];
    return gulp.src(path)
        .pipe($.less({
            paths: [path.join(__dirname, 'less', 'includes')]
        }))
        .pipe($.cssmin())
        .pipe(gulp.dest(DIST + 'css'));
}

gulp.task('compile:scripts', function() {
    return _uglify();
});

gulp.task('compile:styles', function() {
    return _less(FILTER['less']);
});

gulp.task('statics', function() {
    return gulp.src([FILTER['res'], FILTER['html']])
        .pipe($.copy(DIST, {prefix: 2}));
});

gulp.task('build', ['statics'], function() {
    _uglify({
        release: true
    });
    _less();
});

gulp.task('watch', function() {
    gulp.watch(FILTER['js'], function() {
        return _uglify({
            newer: true
        });
    });

    gulp.watch(FILTER['less'], function() {
        return _less();
    });
});

gulp.task('default', function() {
    gulp.start(['statics', 'compile:scripts', 'compile:styles', 'watch']);
});