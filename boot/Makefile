

run:bootsect.bin setup.bin
	dd if=bootsect.bin of=loader.img bs=512 count=1
	dd if=setup.bin of=setup.img bs=1474048 count=1 conv=sync
	dd if=setup.img of=loader.img  seek=1


	#qemu-system-i386 -fda loader.img -boot a
	qemu-system-i386 -fda loader.img -boot a -gdb tcp::1234  -monitor stdio 

	#qemu-system-i386 -fda $(BIN_DIR)/loader.img -boot a -gdb tcp::1234   -monitor stdio seek=1 count=1
    #qemu-system-i386 -fda $(BIN_DIR)/loader.img -boot a -gdb tcp::1234 -monitor stdio -T kernel.ld

bootsect.bin : bootsect.o  Makefile kernel1.ld
	ld -M --oformat binary -m elf_i386 -o bootsect.bin bootsect.o -T kernel1.ld
	#ld  -m elf_i386 -static --oformat binary -N -Ttext 0x7c00 -o bootsect.bin bootsect.o 

bootsect.o : bootsect.s Makefile
	#as --32 bootsect.s -o bootsect.o 
	as --32 -o bootsect.o bootsect.s
	#as --32 -o bootsect.o boot.s		

setup.bin : setup.o   Makefile  main.o functions.o font.o font_code.o
	ld -M  -m elf_i386 -o setup.elf  setup.o -T kernel.ld main.o functions.o font.o font_code.o  
	objcopy -O binary setup.elf setup.bin
	#ld -M --oformat binary -m elf_i386 -o setup.bin setup.o -T kernel.ld main.o font.o
	#ld  -o setup.bin setup.o 

    #ld -M -m elf_i386 -o $(BIN_DIR)/system.elf $(OBJ_DIR)/system.o $(OBJ_DIR)/main.o -T system.lds
    #objcopy -O binary $(BIN_DIR)/system.elf $(BIN_DIR)/system.bin -fno-builtin	


setup.o : setup.s Makefile
	#as --32 bootsect.s -o bootsect.o 
	as --32 -o setup.o setup.s	

main.o : main.c Makefile
	gcc -c main.c -o main.o -m32 -g    #-fno-plt	

functions.o : functions.s Makefile
	as --32 functions.s -o functions.o

font.o : font.c  font.h Makefile 
	gcc -c font.c  -o font.o -m32 -g #-fno-plt #-fno-stack-protector

font_code.o : font_code.c font.h Makefile
	gcc -c font_code.c -o font_code.o -m32	 -g

	
clean :
	rm *.bin *.o *.img #.elf
