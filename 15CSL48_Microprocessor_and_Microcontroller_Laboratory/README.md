How to run assembly code:

1. Run DOSBOX
2. mount C C:\masm32
3. C:
4. Write the file: edit filename.asm
5. Save and Exit
6. Compile: ml /Zi filename.asm
7. Link: link filename.obj
8. Run: debug filename.exe

If any error, delete respective obj and exe files, then compile asm again.