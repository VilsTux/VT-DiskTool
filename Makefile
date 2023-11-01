all: VT-DiskTool.c
	gcc -O2 -s -o vtdtool VT-DiskTool.c
	strip vtdtool

clean:
	rm -f vtdtool 
