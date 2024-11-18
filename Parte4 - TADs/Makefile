all: libs mains

libs:
	gcc -c .\stackSeq\stackSeq.c -o .\stackSeq\Output\stackSeq.o
	gcc -c .\stackLig\stackLig.c -o .\stackLig\Output\stackLig.o

mains:
	gcc .\stackSeq\Output\stackSeq.o .\aPilhaInt.c -o .\Output\aPilhaInt.exe
	gcc .\stackLig\Output\stackLig.o .\bPilhaCalcHP.c -o .\Output\bPilhaCalcHP.exe

run:
#	.\Output\aPilhaInt.exe
	.\Output\bPilhaCalcHP.exe

clean:
	del .\Output\*.* /Q
	del .\stackSeq\Output\*.* /Q
	del .\stackLig\Output\*.* /Q
	