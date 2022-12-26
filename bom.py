import time

class ECU():
    pump_speed = None
    motor_speed = None
    openvantime = None
    bottom_threshold = None
    top_threshold = None
    up_scale = None
    down_scale = None
    prepare_state = None
    run_state = None

    def run(self):
        while True:
            # lien tuc bom cho den khi ap suat dat nguong
            if self.prepare_state == True:
                self.pump(self.pump_speed)
                res = self.cal_stress(openvantime, self.pump_speed)
                if self.bottom_threshold < res < self.top_threshold:
                    self.prepare_state = False

                self.display(res, self.pump_speed, 0)

            # oto bat dau chay
            if self.run_state == True:
                self.motor(self.motor_speed)
                openvantime = self.cal_openvantime(self.motor_speed)
                res = self.cal_stress(openvantime, self.pump_speed)

                if res < self.bottom_threshold:
                    self.pump_speed = self.pump_speed * self.up_scale
                    self.pump(self.pump_speed)

                if res > self.top_threshold:
                    self.pump_speed = self.pump_speed * self.down_scale
                    self.pump(self.pump_speed)

                if self.bottom_threshold < res < self.top_threshold:
                    pass

                self.display(res, self.pump_speed, self.motor_speed)

    def pump(speed):
        pass

    def motor(speed):
        pass

    def cal_stress(openvantime, pump_speed):
        return None

    def cal_openvantime(motor_speed):
        return None

    def van(open_time):
        time.sleep(open_time)

    def display(stress, pump_speed, motor_speed):
        print(stress, pump_speed, motor_speed)

#////////////////////////////////////////////////////////////////////////////////
# Event/ Interupt
ecu = ECU()
default_open_van_time = 0.0001
default_motor_speed = 1000
default_pump_speed = 500
first_mode_motor = 1200
second_mode_motor = 1400

def turnOn():
    ecu.prepare_state = True
    ecu.openvantime = default_open_van_time
    ecu.pump_speed = default_pump_speed
    ecu.motor_speed = default_motor_speed

def turnOff():
    ecu.run_state = False
    ecu.motor_speed = 0

def mode1():
    ecu.run_state = True
    ecu.motor_speed = first_mode_motor

def mode2():
    ecu.run_state = True
    ecu.motor_speed = second_mode_motor
