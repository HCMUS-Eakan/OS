# Hệ điều hành

# Đồ án 3 : Linux Kernel ![license][1]

Thực hiện bởi: 	
* Nguyễn Quang Trường - MSSV: `19127608`
* Nguyễn Trần Ngọc Tú - MSSV: `19127610`
* Đỗ Đình Văn         - MSSV: `19127624` 

## KernelModule : Mục tiêu hiểu về Linux kernel module và hệ thống quản lý file và device trong linux, giao tiếp giữa tiến trình ở user space và kernel space.
- Viết một module dùng để tạo ra số ngẫu nhiên.
- Module này sẽ tạo một character device để cho phép các tiến trình ở user space có thể open và read các số ngẫu nhiên
   ### Linux Kernel Module - Random Number Generator Character Device Driver
   Mã nguồn trong file **randNum.c** dùng để biên dịch ra module là một character device driver, có chức năng cho phép các tiến trình ở user space mở và đọc một số ngẫu nhiên từ file thiết bị của device này.

   ### Hướng dẫn sử dụng
   1. Mở Terminal tại thư mục KernelModule, gõ lệnh `make` , file chardevdrv.ko sẽ được tạo ra
   
   2. Gõ lệnh `modinfo randNum.ko` để xem thông tin của module
   
   3. Gõ lệnh `sudo insmod randNum.ko` để cài đặt module driver này
   
   4. Gõ lệnh `lsmod | grep randNum` để xem module đã được cài đặt thành công chưa
   
   5. Để đọc một số ngẫu nhiên từ device này, ta dùng lệnh sau :
	   ```
      sudo dd if=/dev/random bs=4 count=1 | hexdump -C      
      ```
      hoặc biên dịch file mã nguồn **testRand.c** bằng lệnh
      ```  	
      gcc testRand.c -o test
      ```
      rồi chạy tập tin thực thi **test** 
   	
   	>Lệnh trên đọc 4 byte từ file thiết bị `/dev/random` và xuất ra màn hình Terminal dưới dạng kí tự hexa (dùng lệnh `hexdump`). Chạy lệnh này nhiều lần, mỗi lần sẽ cho ra các kết quả ngẫu nhiên khác nhau. Tương tự với tập tin thực thi **test**, nhưng kết quả hiển thị là số thập phân.
   	
   6. Để gỡ module này, gõ lệnh `sudo rmmod random`
   
   7. Để dọn sạch các file được tạo ra trong thư mục trong quá trình biên dịch, gõ lệnh `make clean`
   
  
[1]:https://camo.githubusercontent.com/7de7f171e34eba428ffe0a84a2b2297431f55ac3/68747470733a2f2f696d672e736869656c64732e696f2f636f636f61706f64732f6c2f537769667453696d706c6966792e7376673f7374796c653d666c6174
