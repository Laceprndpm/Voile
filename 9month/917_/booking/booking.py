from types import TracebackType
import threading
from typing import Type
from selenium import webdriver
from selenium.webdriver.common.by import By
import booking.constants as const
from selenium.webdriver.common.action_chains import ActionChains
import time
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys

class booking(webdriver.Firefox):
# 初始化函数
    def __init__(self,teardown=True):
        super(booking,self).__init__()
        # 是否自动关闭
        self.teardown = teardown
        # 隐式等待
        self.implicitly_wait(10)
        # 全屏
        self.maximize_window()
        # 显式等待
        self.wait = WebDriverWait(self,10)


# 退出
    def __exit__(self, exc_type: type[BaseException] | None, exc: BaseException | None, traceback: TracebackType | None):
        if self.teardown:
            self.quit()
# 加载页面
    def land_frist_page(self):
        self.get(f'https://{const.domain}')

# 
    def login(self):
        username = self.find_element(By.CLASS_NAME,'user-pic')
        passwd = self.find_element(By.CLASS_NAME,'password-pic')
        username.send_keys(f'{const.username}')
        passwd.send_keys(f'{const.passwd}')
        enter = self.find_element(By.ID,'index_login_btn')
        enter.click()

    def change_page(self):
        button1=self.find_element(By.ID,'common_app')
        button1.click()
        button2=self.find_element(By.CSS_SELECTOR,'a[title="教务系统"]')
        button2.click()
        original_window = self.current_window_handle
        all_windows = self.window_handles
        for window in all_windows:
            if window != original_window:
                self.switch_to.window(window)
                break
        button3 = self.find_element(By.XPATH, '//h4/a[text()="新版教务系统学生端（试运行）"]')
        # button3 = self.find_element(By.CSS_SELECTOR, 'a[href="https://wvpn.ahu.edu.cn/https/77726476706e69737468656265737421fae00f9d2f2526557a1dc7af96/student/sso/login"]')
        button3.click()

        try:
            button5 = self.wait.until(EC.visibility_of_element_located((By.ID,'wechatOfficialBindingConfirm')))
            # button5 = self.find_element(By.ID,'wechatOfficialBindingConfirm')
            button5.click()
        except:
            pass
        try:
            # self.find_element(By.CSS_SELECTOR,"span[style='margin-left:5px;font-size:14px;']")
            # button4 = self.find_element(By.CSS_SELECTOR,"span[style='margin-left:5px;font-size:14px;']")
            # button4.click()
            hover_element = self.find_element(By.CLASS_NAME, 'dropdown-toggle')
            actions = ActionChains(self)
            actions.move_to_element(hover_element).perform()
            button6=self.find_element(By.ID,'drop_01.04.01')
            button6.click()
        except:
            print('Error on line 72')
        # 滚动到页面底部
        # 此时到了挑选选课部分
        # 检测到iframe，需要切换页面
        iframe_element = self.find_element(By.XPATH, "/html/body/div[1]/div/div/div[2]/iframe")
        self.switch_to.frame(iframe_element)
        self.find_element(By.TAG_NAME, "body").send_keys(Keys.SPACE)
        buttons=self.find_elements(By.CLASS_NAME,'el-button--primary')
        button7=buttons[-1]
        button7.click()
# href="/https/77726476706e69737468656265737421fae00f9d2f2526557a1dc7af96/student/for-std/course-select"
    def pick(self):
        temp=[]
        self.switch_to.window(self.window_handles[-1])
        self.wait = WebDriverWait(self,10)
        self.wait.until(EC.visibility_of_element_located((By.CLASS_NAME,'el-table__row')))
        elements = self.find_elements(By.CLASS_NAME,'el-table__row')
        for element in elements:
            info=element.find_element(By.XPATH,'./td[3]/div/div/div[2]/span[1]')
            if info.text in const.target_list:
                temp_button = element.find_element(By.XPATH,'./td[1]/div/button')
                temp.append(temp_button)
        return temp
    
    def handle_courses(self,course_elements):
        """处理课程列表的函数"""
        threads = []
        for element in course_elements:
            # 创建一个新线程来点击课程
            thread = threading.Thread(target=self.click_course, args=(element,))
            threads.append(thread)
            thread.start()

            for thread in threads:
                thread.join()

    def click_course(self, element):
        """点击课程元素的函数"""
        while(1):
            try:
                element.click()
                print(f"Clicked on: {element.text}")
            except:
                continue
            self.close_window()
            time.sleep(1)


    def close_window(self):
        button=self.find_element(By.XPATH,'/html/body/div[1]/div/div[3]/div[1]/div/div/div[2]/div[2]/div/div/div[3]/div/div[3]/span/button/span')
        button.click()

# /html/body/div[1]/div/div[3]/div[1]/div/div/div[2]/div[2]/div/div/div[2]/div/div[1]/div[3]/table/tbody/tr[6]
# /html/body/div[1]/div/div[3]/div[1]/div/div/div[2]/div[2]/div/div/div[2]/div/div[1]/div[3]/table/tbody/tr[6]/td[3]/div/div/div[2]/span[1]
# /html/body/div[1]/div/div[3]/div[1]/div/div/div[2]/div[2]/div/div/div[2]/div/div[1]/div[3]/table/tbody/tr[6]/td[1]/div/button
