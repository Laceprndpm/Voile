import time
import tkinter as tk
from tkinter import messagebox

def show_popup():
    root = tk.Tk()
    root.withdraw()  # 隐藏主窗口
    root.attributes('-topmost', True)  # 使弹窗在最上层显示
    messagebox.showinfo("提醒", "这是一个定时提醒")
    root.destroy()  # 关闭弹窗

def main():
    while True:
        # 获取当前系统时间
        current_time = time.strftime("%H:%M")
        
        # 检查是否时间 >= 13:30 或者是否为 11:45 或 11:50 进行测试
        if current_time >= "13:30" or current_time == "11:45" or current_time == "11:50":
            show_popup()  # 弹窗提醒
            
            # 如果是 11:45 或 11:50 测试弹窗，休眠到下一分钟再检查
            if current_time == "11:45" or current_time == "11:50":
                time.sleep(60)
            else:
                time.sleep(5 * 60)  # 如果是 >= 13:30，则每隔 5 分钟弹窗
            
        else:
            time.sleep(60)  # 时间未到时每 1 分钟检查一次

if __name__ == "__main__":
    main()
