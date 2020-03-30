# quatang
arduino
Pet food alarm
Sản  phẩm còn chưa hoàn hảo vì t làm hơi vội, còn nhiều vấn đề chưa giải quyết xong, c có thể tự phát triển trên cơ sở source code
Cắm adapter để kết nối vs board arduino 
SAu vài giây, màn hình oled hiển thị 2 dòng:
 -Time
 -Alarm
Set alarm bằng cách giữ nút (#) trên keypad, sau đó nhập thời gian theo thứ tự giờ phút giây. Ví dụ: 14:30:00(đây là lỗi đầu tiên. bắt buộc phải set 00 second)
Sau khi đồng hồ chạy đến giờ báo thức, động cơ sẽ mở đường dẫn thức ăn để thức ăn rơi xuống trong khoảng 7s(c có thể chỉnh theo ý c tránh việc thiếu thức ăn và lạng phí)
Trong trường hợp thời gian mở quá lâu c có thể giữ nút C trên keypad để khóa đường ống khi đó thời gian báo thức sẽ tự động chuyển về dạng 
xx:60:xx

Bên phần cứng t có cắt 2 cái chai. Chắc c nên dùng cái có nắp vì mèo nhà c hơi to, c có thể tháo lắp dễ dàng tiện cho việc rửa sạch
t cũng hơ lửa qua phần nắp r, chắc cũng k quá sắc tới đứt tay đâu

Về cơ bản là đơn giản v thôi, c thông cảm vì t cũng chỉ nảy ra ý tưởng k lâu và bị bug suốt nên t k thể làm chuẩn chỉ dc.

