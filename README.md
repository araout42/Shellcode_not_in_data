<h1>Shellcode not in Data</h1>

the script takes a file as argument the file must containt a raw shellcode such as :
![msfvenom_screen2](https://github.com/araout42/Shellcode_not_in_data/assets/41875074/2e95e46c-4285-459f-8c63-34737e2804bb)


a very simple static evasion method would be to stop declaring your shellcode in the DATA section and instead declare it at RUNTIME

<h3>this very simple script will allow you to go from this : </h3>

![loader_screen](https://github.com/araout42/Shellcode_not_in_data/assets/41875074/1cdfe0e7-fcd2-49d8-a475-da50c142a082)
![VT_Screen1](https://github.com/araout42/Shellcode_not_in_data/assets/41875074/7f4f06fd-9cb2-4fbe-913c-6254fe82612c)


<h3>To this :</h3>

![loader_screen2](https://github.com/araout42/Shellcode_not_in_data/assets/41875074/8590ba99-cd2a-47d8-be43-a68801477cf8)
![VT_Screen2](https://github.com/araout42/Shellcode_not_in_data/assets/41875074/0208468a-68ec-4cc0-9227-bb573132e7a9)


Indeed declaring a shellcode in DATA would make it written clear inside of the file... this defeat the purpose of any static evasion
Now declare the shellcode in RUNTIME so you avoid getting easilly detected by stati analysis 
