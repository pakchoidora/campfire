const gulp = require('gulp');
const $ = require('gulp-load-plugins')();
const path = require('path');
const stylish = require('jshint-stylish');

const DIST = './dist/';
const FILTER = {
    less: 'sources/styles/**/*.less',
    js: 'sources/**/*.js'
};

function _uglify() {
    return gulp.src(FILTER['js'])
        .pipe($.jshint())
        .pipe($.jshint.reporter(stylish))
        .pipe($.uglify({
            mangle: true
        }))
        .pipe(gulp.dest(DIST + 'js'));
}

function _less(options) {
    let path = Array.isArray(FILTER['less']) ? FILTER['less'] : [FILTER['less']];
    return gulp.src(path)
        .pipe($.less({
            paths: [path.join(__dirname, 'less', 'includes')]
        }))
        .pipe($.cssmin())
        .pipe(gulp.dest(DIST + 'css'));
}

gulp.task('hint', () => {
    return gulp.src(FILTER['js'])
        .pipe($.jshint())
        .pipe($.jshint.reporter(stylish));
});

gulp.task('compile:scripts', () => {
    return _uglify();
});

gulp.task('compile:styles', () => {
    return _less(FILTER['less']);
});

gulp.task('build', ['statics'], () => {
    _uglify({
        release: true
    });
    _less();
});

gulp.task('watch', () => {
    gulp.watch(FILTER['js'], () => {
        return _uglify({
            newer: true
        });
    });

    gulp.watch(FILTER['less'], () => {
        return _less();
    });
});

gulp.task('default', () => {
    gulp.start(['compile:scripts', 'compile:styles', 'watch']);
});