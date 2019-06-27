NIMC = nim
APPNAME = campfire
DATE = $(shell date +%Y-%m-%d)

SOURCES = $(shell find src -name '*.nim')

ENTRY = src/campfire.nim

$(APPNAME)-debug: src/*.nim
	$(NIMC) c -d:debug -o:build/$@ $(ENTRY)
	cp assets/config.ini build

$(APPNAME): src/*.nim
	$(NIMC) c -d:release -o:build/$@ $(ENTRY)

clean:
	rm -vrf src/nimcache $(APPNAME) $(APPNAME)-debug || true

run: $(APPNAME)
	cp -r assets build
	./build/$(APPNAME)

rund: $(APPNAME)-debug
	cp -r assets build
	./build/$(APPNAME)-debug

windows: $(SOURCES)
	${NIMC} c -d:release -d:windows --threads:on -o:winversion/${APPNAME}.exe $(ENTRY)
	cp -r assets winversion
	cp config.ini winversion
	cp *.dll winversion
	unix2dos winversion/config.ini
	find winversion/assets/ -name '*.wav' -delete
	rm ${APPNAME}-${DATE}-win32.zip || true
	cd winversion; \
	zip -r ../${APPNAME}-${DATE}-win32.zip .

linux64: $(SOURCES)
	${NIMC} c -d:release --threads:on -o:linux/${APPNAME}.x86_64 $(ENTRY)

linux32: $(SOURCES)
	${NIMC} c -d:release -d:linux32 --threads:on -o:linux/${APPNAME}.x86 $(ENTRY)

linux: linux32 linux64
	cp -r assets linux
	cp config.ini linux
	find linux/assets/ -name '*.wav' -delete
	cd linux; \
	tar czf ../${APPNAME}-${DATE}-linux.tar.gz .

osx: $(SOURCES)
	${NIMC} c -d:release -d:osx --threads:off -o:${APPNAME}.app/Contents/MacOS/campfire $(ENTRY)
	cp -r assets ${APPNAME}.app/Contents/Resources/
	cp config.ini ${APPNAME}.app/Contents/Resources/
	find ${APPNAME}.app/Contents/Resources/assets/ -name '*.wav' -delete
	rm ${APPNAME}-${DATE}-osx.zip || true
	zip --symlinks -r ${APPNAME}-${DATE}-osx.zip ${APPNAME}.app

.PHONY: clean run rund
