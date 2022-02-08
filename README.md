# สร้างเกม c++ ด้วย SFML
สร้าง Board Game 2D โดยดัดแปลงเนื้อหาเกมจาก Survive Escape from Atlantis!
# วิชา Computer Programming รหัสวิชา 261102
# รายชื่อสมาชิกกลุ่ม
1. นายธัญธร คงเมือง รหัส 640610679
2. นายภาธรธฤต ไชยวงศ์ รหัส 640610681
3. นายภูมิพัฒน์  วัฒนประสิทธิ์ รหัส 640610682
4. นายวริทธิ์ มโนแก้ว รหัส 640610683
# รายงานความคืบหน้า
 * 13/01/2565
    ประกาศรายชื่อสมาชิกกลุ่ม
 * 17/01/2565
    ส่งหัวข้อโปรเจค
 * 18/01/2565
    - รายงานความคืบหน้าครั้งที่ 1
    - ทุกคนในกลุ่มเริ่มศึกษาความรู้เกี่ยวกับ Unreal Engine
 * 28/01/2565
    ได้มีการสร้าง Github
 * 31/01/2565
    - เปลี่ยน library ในการทำจาก Unreal engine --> SFML
    - เริ่มวาดภาพตัวละคร โดย ธัญธร คงเหมือง
 * 08/02/2565
    - ระบบ Multiplayer เสร็จสิ้น
    - อัพไฟล์พื้นฐานลง github
# สิ่งที่ต้องทำ
 * ระบบ Setup
    - สร้าง Board game ใส่รูปภาพแต่ละตำแหน่งบนจอ
    - random พื้นที่เกาะ, random การ์ดใต้เกาะ
    - ระบบ player สลับกันวางตัวละคร
    - random ปลาฉลาม และ โลมาอย่างละ 1 ตัวในน้ำ
 * phase 1
    - เช็คว่า player มีการ์ดในตัวไหม ถ้ามีให้เลือกลง 1 ใบ หรือไม่ลงก็ได้
 * phase 2
    - ระบบเดินตัวละคร บนบกเดินได้ 3 ช่อง ในน้ำเดินได้ 1 ช่อง หรือไม่เดินเลยก็ได้
 * phase 3
    - ระบบให้ player ทำลายเกาะโดยต้องเปิด ทราย --> ป่า --> หิน
    - ระบบเปิดการ์ดบนเกาะ :: การ์ดที่เก้บไว้ใช้ได้ : ระบบเพิ่มการ์ดให้ผู้เล่นในตำแหน่ง c
    - ระบบเปิดการ์ดบนเกาะ :: การ์ดที่ต้องใช้ทันที : เปิดการ์ดแล้วเกิด Effect ตามการ์ด
    - ระบบเปิดการ์ดบนเกาะ :: ระบบจบเกม : หากเปิดได้ภูเขาไฟ เช็คว่าใครชนะ และแสดงผลที่หน้าจอ
    - ระบบทอยลูกเต๋า :: ได้ซีเซอเพ้น : เลือกให้ซีเซอเพ้นเดินได้ 1 ช่อง และเช็คว่ากินคนไหม
    - ระบบทอยลูกเต๋า :: ได้ปลาฉลาม : เลือกให้ปลาฉลามเดินได้ 2 ช่อง และเช็คว่ากินคนไหม
    - ระบบทอยลูกเต๋า :: ได้โลมา : เดินได้ 3 ช่อง 

