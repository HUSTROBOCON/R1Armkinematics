import sys
import xml.etree.ElementTree as ET
import yaml
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout,
                             QHBoxLayout, QLabel, QLineEdit, QPushButton,
                             QGroupBox, QMessageBox, QFileDialog, QScrollArea,
                             QGridLayout,QComboBox)
from PyQt6.QtCore import Qt

class URDFEditor(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.tree = None
        self.root = None
        self.current_joint = None
        self.joint_buttons = []

    def initUI(self):
        self.setWindowTitle('URDF Editor')
        self.setGeometry(100, 100, 800, 600)

        # 创建主窗口部件
        main_widget = QWidget()
        self.setCentralWidget(main_widget)
        layout = QHBoxLayout()

        # 左侧面板 - 关节选择
        left_panel = QGroupBox("Joints")
        left_layout = QVBoxLayout()

        # 文件操作按钮
        file_btn_layout = QHBoxLayout()
        self.load_btn = QPushButton("Load URDF")
        self.save_btn = QPushButton("Save URDF")
        file_btn_layout.addWidget(self.load_btn)
        file_btn_layout.addWidget(self.save_btn)

        # 创建滚动区域用于关节按钮
        scroll = QScrollArea()
        scroll.setWidgetResizable(True)
        scroll.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)

        self.joint_button_widget = QWidget()
        self.joint_button_layout = QGridLayout()
        self.joint_button_widget.setLayout(self.joint_button_layout)
        scroll.setWidget(self.joint_button_widget)

        left_layout.addLayout(file_btn_layout)
        left_layout.addWidget(QLabel("Select Joint:"))
        left_layout.addWidget(scroll)
        left_panel.setLayout(left_layout)

        # 右侧面板 - 参数设置
        right_panel = QGroupBox("Joint Parameters")
        right_layout = QVBoxLayout()

        # 显示当前选中的关节
        self.current_joint_label = QLabel("Current Joint: None")
        right_layout.addWidget(self.current_joint_label)

        # Command Interface 参数
        cmd_group = QGroupBox("Command Interface")
        cmd_layout = QVBoxLayout()

        # Position
        pos_layout = QVBoxLayout()
        pos_layout.addWidget(QLabel("Position Limits:"))
        pos_min_layout = QHBoxLayout()
        pos_min_layout.addWidget(QLabel("Min:"))
        self.pos_min = QLineEdit()
        pos_min_layout.addWidget(self.pos_min)
        pos_layout.addLayout(pos_min_layout)

        pos_max_layout = QHBoxLayout()
        pos_max_layout.addWidget(QLabel("Max:"))
        self.pos_max = QLineEdit()
        pos_max_layout.addWidget(self.pos_max)
        pos_layout.addLayout(pos_max_layout)
        cmd_layout.addLayout(pos_layout)

        # Velocity
        vel_layout = QVBoxLayout()
        vel_layout.addWidget(QLabel("Velocity Limits:"))
        vel_min_layout = QHBoxLayout()
        vel_min_layout.addWidget(QLabel("Min:"))
        self.vel_min = QLineEdit()
        vel_min_layout.addWidget(self.vel_min)
        vel_layout.addLayout(vel_min_layout)

        vel_max_layout = QHBoxLayout()
        vel_max_layout.addWidget(QLabel("Max:"))
        self.vel_max = QLineEdit()
        vel_max_layout.addWidget(self.vel_max)
        vel_layout.addLayout(vel_max_layout)
        cmd_layout.addLayout(vel_layout)

        # Effort
        eff_layout = QVBoxLayout()
        eff_layout.addWidget(QLabel("Effort Limits:"))
        eff_min_layout = QHBoxLayout()
        eff_min_layout.addWidget(QLabel("Min:"))
        self.eff_min = QLineEdit()
        eff_min_layout.addWidget(self.eff_min)
        eff_layout.addLayout(eff_min_layout)

        eff_max_layout = QHBoxLayout()
        eff_max_layout.addWidget(QLabel("Max:"))
        self.eff_max = QLineEdit()
        eff_max_layout.addWidget(self.eff_max)
        eff_layout.addLayout(eff_max_layout)
        cmd_layout.addLayout(eff_layout)

        cmd_group.setLayout(cmd_layout)

        # State Interface 参数
        state_group = QGroupBox("State Interface")
        state_layout = QVBoxLayout()

        init_val_layout = QHBoxLayout()
        init_val_layout.addWidget(QLabel("Initial Position:"))
        self.init_pos = QLineEdit()
        init_val_layout.addWidget(self.init_pos)
        state_layout.addLayout(init_val_layout)

        state_group.setLayout(state_layout)

        # 添加更新按钮
        self.update_btn = QPushButton("Update Joint Parameters")

        right_layout.addWidget(cmd_group)
        right_layout.addWidget(state_group)
        right_layout.addWidget(self.update_btn)
        right_panel.setLayout(right_layout)

        # 设置主布局
        layout.addWidget(left_panel, 1)  # 1是拉伸因子
        layout.addWidget(right_panel, 2)  # 2是拉伸因子
        main_widget.setLayout(layout)

        # 连接信号和槽
        self.load_btn.clicked.connect(self.load_urdf)
        self.save_btn.clicked.connect(self.save_urdf)
        self.update_btn.clicked.connect(self.update_joint_params)

        # 修改initUI中的IMU Configuration部分
        imu_group = QGroupBox("IMU Configuration")
        imu_layout = QVBoxLayout()

        # IMU Link Selection
        imu_link_layout = QHBoxLayout()
        imu_link_layout.addWidget(QLabel("Mount Link:"))
        self.imu_link_combo = QComboBox()
        imu_link_layout.addWidget(self.imu_link_combo)
        imu_layout.addLayout(imu_link_layout)

        # Update rate
        update_rate_layout = QHBoxLayout()
        update_rate_layout.addWidget(QLabel("Update Rate:"))
        self.imu_update_rate = QLineEdit("100")
        update_rate_layout.addWidget(self.imu_update_rate)
        imu_layout.addLayout(update_rate_layout)

        imu_group.setLayout(imu_layout)
        right_layout.addWidget(imu_group)


    def create_joint_buttons(self, joint_names):
        # 清除现有按钮
        for button in self.joint_buttons:
            button.deleteLater()
        self.joint_buttons.clear()

        # 计算按钮布局
        num_joints = len(joint_names)
        cols = min(1, num_joints)  # 最多3列
        rows = (num_joints + cols - 1) // cols  # 向上取整计算行数

        # 创建新按钮
        for i, name in enumerate(joint_names):
            button = QPushButton(name)
            button.setCheckable(True)
            button.clicked.connect(lambda checked, n=name: self.joint_button_clicked(n))
            row = i // cols
            col = i % cols
            self.joint_button_layout.addWidget(button, row, col)
            self.joint_buttons.append(button)

        # 设置按钮大小策略
        for button in self.joint_buttons:
            button.setMinimumWidth(100)
            button.setMinimumHeight(30)

    def joint_button_clicked(self, joint_name):
        # 更新按钮状态
        for button in self.joint_buttons:
            button.setChecked(button.text() == joint_name)

        # 更新当前关节
        self.current_joint = None
        ros2_control = self.root.find(".//ros2_control")
        if ros2_control is not None:
            for joint in ros2_control.findall(".//joint"):
                if joint.get('name') == joint_name:
                    self.current_joint = joint
                    self.current_joint_label.setText(f"Current Joint: {joint_name}")
                    self.load_joint_params()
                    break

    def load_urdf(self):
        filename, _ = QFileDialog.getOpenFileName(self, "Open URDF file", "", "URDF files (*.urdf);;All files (*.*)")
        if filename:
            try:
                self.tree = ET.parse(filename)
                self.root = self.tree.getroot()

                # 检查是否存在ros2_control标签
                ros2_control = self.root.find(".//ros2_control")
                if ros2_control is None:
                    # 如果不存在，创建新的ros2_control元素
                    ros2_control = ET.Element("ros2_control", name="GazeboSystem", type="system")
                    hardware = ET.SubElement(ros2_control, "hardware")
                    ET.SubElement(hardware, "plugin").text = "gazebo_ros2_control/GazeboSystem"
                    self.root.append(ros2_control)

                # 检查是否存在gazebo标签
                gazebo = self.root.find(".//gazebo")
                if gazebo is None:
                    # 如果不存在，创建新的gazebo元素
                    gazebo = ET.Element("gazebo")
                    self.root.append(gazebo)

                # 检查是否存在gazebo_ros2_control插件
                gazebo_plugin = gazebo.find(".//plugin[@filename='libgazebo_ros2_control.so']")
                if gazebo_plugin is None:
                    # 如果不存在，创建新的plugin元素
                    gazebo_plugin = ET.SubElement(gazebo, "plugin",
                                                  filename="libgazebo_ros2_control.so",
                                                  name="gazebo_ros2_control")
                    ET.SubElement(gazebo_plugin, "parameters").text = "(Please specify the path to your effort_control.yaml file)"

                # 获取所有非fixed关节
                joints = []
                for joint in self.root.findall(".//joint"):
                    if joint.get('type') != 'fixed':
                        joints.append(joint.get('name'))

                # 检查每个关节是否已经在ros2_control中
                existing_joints = set()
                for joint in ros2_control.findall(".//joint"):
                    existing_joints.add(joint.get('name'))

                # 为未配置的关节添加配置
                for joint_name in joints:
                    if joint_name not in existing_joints:
                        joint_elem = ET.SubElement(ros2_control, "joint", name=joint_name)

                        # 添加command interfaces
                        cmd_pos = ET.SubElement(joint_elem, "command_interface", name="position")
                        ET.SubElement(cmd_pos, "param", name="min").text = "-100.0"
                        ET.SubElement(cmd_pos, "param", name="max").text = "100.0"

                        cmd_vel = ET.SubElement(joint_elem, "command_interface", name="velocity")
                        ET.SubElement(cmd_vel, "param", name="min").text = "-20000.0"
                        ET.SubElement(cmd_vel, "param", name="max").text = "20000.0"

                        cmd_eff = ET.SubElement(joint_elem, "command_interface", name="effort")
                        ET.SubElement(cmd_eff, "param", name="min").text = "-1000"
                        ET.SubElement(cmd_eff, "param", name="max").text = "1000"

                        # 添加state interfaces
                        pos_state = ET.SubElement(joint_elem, "state_interface", name="position")
                        ET.SubElement(pos_state, "param", name="initial_value").text = "0.0"
                        ET.SubElement(joint_elem, "state_interface", name="velocity")
                        ET.SubElement(joint_elem, "state_interface", name="effort")

                # 更新界面
                self.load_joints()

                # 更新IMU link选择框
                self.imu_link_combo.clear()
                for link in self.root.findall(".//link"):
                    self.imu_link_combo.addItem(link.get('name'))

                QMessageBox.information(self, "Success", "URDF file loaded and configured successfully!")

            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to load URDF: {str(e)}")



    def load_joints(self):
        joint_names = []
        ros2_control = self.root.find(".//ros2_control")
        if ros2_control is not None:
            for joint in ros2_control.findall(".//joint"):
                name = joint.get('name')
                if name:
                    joint_names.append(name)
        self.create_joint_buttons(joint_names)

    def load_joint_params(self):
        if not self.current_joint:
            return

        # Load position limits
        pos_cmd = self.current_joint.find(".//command_interface[@name='position']")
        if pos_cmd is not None:
            self.pos_min.setText(pos_cmd.find("param[@name='min']").text)
            self.pos_max.setText(pos_cmd.find("param[@name='max']").text)

        # Load velocity limits
        vel_cmd = self.current_joint.find(".//command_interface[@name='velocity']")
        if vel_cmd is not None:
            self.vel_min.setText(vel_cmd.find("param[@name='min']").text)
            self.vel_max.setText(vel_cmd.find("param[@name='max']").text)

        # Load effort limits
        eff_cmd = self.current_joint.find(".//command_interface[@name='effort']")
        if eff_cmd is not None:
            self.eff_min.setText(eff_cmd.find("param[@name='min']").text)
            self.eff_max.setText(eff_cmd.find("param[@name='max']").text)

        # Load initial position
        pos_state = self.current_joint.find(".//state_interface[@name='position']")
        if pos_state is not None:
            init_val = pos_state.find("param[@name='initial_value']")
            if init_val is not None:
                self.init_pos.setText(init_val.text)
            else:
                self.init_pos.setText("")

    # 在load_urdf方法中添加更新IMU link选择：

    def generate_yaml(self):
        if not self.root:
            QMessageBox.warning(self, "Warning", "Please load a URDF file first!")
            return

        # 获取所有joints，只从ros2_control部分获取
        joints = []
        ros2_control = self.root.find(".//ros2_control")
        if ros2_control is not None:
            for joint in ros2_control.findall(".//joint"):
                joint_name = joint.get('name')
                if joint_name and joint_name not in joints:  # 避免重复
                    joints.append(joint_name)

        # 如果ros2_control中没有找到关节，则从普通joint标签中查找
        if not joints:
            for joint in self.root.findall(".//joint"):
                if joint.get('type') != 'fixed':  # 排除fixed类型的关节
                    joint_name = joint.get('name')
                    if joint_name and joint_name not in joints:  # 避免重复
                        joints.append(joint_name)

        yaml_content = {
            'controller_manager': {
                'ros__parameters': {
                    'update_rate': 1000,
                    'effort_controller': {
                        'type': 'effort_controllers/JointGroupEffortController'
                    },
                    'joint_state_broadcaster': {
                        'type': 'joint_state_broadcaster/JointStateBroadcaster'
                    }
                }
            },
            'effort_controller': {
                'ros__parameters': {
                    'joints': joints
                }
            }
        }

        # 保存YAML文件
        filename, _ = QFileDialog.getSaveFileName(self, "Save YAML file", "", "YAML files (*.yaml);;All files (*.*)")
        if filename:
            try:
                with open(filename, 'w') as f:
                    yaml.dump(yaml_content, f, default_flow_style=False, sort_keys=False, indent=2)
                QMessageBox.information(self, "Success", "YAML file generated successfully!")
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to save YAML: {str(e)}")



    def update_joint_params(self):
        if not self.current_joint:
            return

        try:
            # Update position limits
            pos_cmd = self.current_joint.find(".//command_interface[@name='position']")
            if pos_cmd is not None:
                pos_cmd.find("param[@name='min']").text = self.pos_min.text()
                pos_cmd.find("param[@name='max']").text = self.pos_max.text()

            # Update velocity limits
            vel_cmd = self.current_joint.find(".//command_interface[@name='velocity']")
            if vel_cmd is not None:
                vel_cmd.find("param[@name='min']").text = self.vel_min.text()
                vel_cmd.find("param[@name='max']").text = self.vel_max.text()

            # Update effort limits
            eff_cmd = self.current_joint.find(".//command_interface[@name='effort']")
            if eff_cmd is not None:
                eff_cmd.find("param[@name='min']").text = self.eff_min.text()
                eff_cmd.find("param[@name='max']").text = self.eff_max.text()

            # Update initial position
            pos_state = self.current_joint.find(".//state_interface[@name='position']")
            if pos_state is not None:
                init_val = pos_state.find("param[@name='initial_value']")
                if init_val is not None:
                    init_val.text = self.init_pos.text()
                elif self.init_pos.text():
                    ET.SubElement(pos_state, "param", name="initial_value").text = self.init_pos.text()

            QMessageBox.information(self, "Success", "Joint parameters updated successfully!")

        except Exception as e:
            QMessageBox.critical(self, "Error", f"Failed to update parameters: {str(e)}")

    def save_urdf(self):
        if not self.tree:
            QMessageBox.warning(self, "Warning", "No URDF file loaded!")
            return

        # 首先询问是否保存YAML文件
        reply = QMessageBox.question(self, 'Save YAML',
                                     'Would you like to save the YAML file for effort control?',
                                     QMessageBox.StandardButton.Yes |
                                     QMessageBox.StandardButton.No)

        if reply == QMessageBox.StandardButton.Yes:
            # 先保存YAML文件
            yaml_path = self.generate_yaml()
            # 删除了这里的 return，这样即使 yaml_path 为 None 也会继续执行

            # 如果成功保存了YAML文件，更新URDF中的YAML路径
            if yaml_path:
                gazebo = self.root.find(".//gazebo")
                if gazebo is not None:
                    plugin = gazebo.find(".//plugin[@filename='libgazebo_ros2_control.so']")
                    if plugin is not None:
                        parameters = plugin.find("parameters")
                        if parameters is not None:
                            parameters.text = yaml_path
                        else:
                            ET.SubElement(plugin, "parameters").text = yaml_path

        # 获取选中的IMU挂载链接和更新频率
        selected_link = self.imu_link_combo.currentText()
        update_rate = self.imu_update_rate.text()

        if selected_link:
            # 检查并移除已存在的相同reference的gazebo配置
            for gazebo in self.root.findall(f".//gazebo[@reference='{selected_link}']"):
                self.root.remove(gazebo)

            # 创建新的IMU配置，使用选中的link作为reference
            imu_gazebo = ET.Element("gazebo", reference=selected_link)
            sensor = ET.SubElement(imu_gazebo, "sensor", name="br_imu", type="imu")

            ET.SubElement(sensor, "always_on").text = "true"
            ET.SubElement(sensor, "update_rate").text = update_rate

            imu = ET.SubElement(sensor, "imu")

            # Angular velocity configuration
            ang_vel = ET.SubElement(imu, "angular_velocity")
            for axis in ['x', 'y', 'z']:
                axis_elem = ET.SubElement(ang_vel, axis)
                noise = ET.SubElement(axis_elem, "noise", type="gaussian")
                ET.SubElement(noise, "mean").text = "0.0"
                ET.SubElement(noise, "stddev").text = "2e-4"

            # Linear acceleration configuration
            lin_acc = ET.SubElement(imu, "linear_acceleration")
            for axis in ['x', 'y', 'z']:
                axis_elem = ET.SubElement(lin_acc, axis)
                noise = ET.SubElement(axis_elem, "noise", type="gaussian")
                ET.SubElement(noise, "mean").text = "0.0"
                ET.SubElement(noise, "stddev").text = "1.7e-2"

            # Add plugin configuration
            plugin = ET.SubElement(sensor, "plugin",
                                   name="bytes_imu",
                                   filename="libgazebo_ros_imu_sensor.so")
            ros = ET.SubElement(plugin, "ros")
            ET.SubElement(ros, "namespace").text = "imu"
            ET.SubElement(ros, "remapping").text = "~/out:=data"
            ET.SubElement(plugin, "initial_orientation_as_reference").text = "false"

            self.root.append(imu_gazebo)

        # 最后保存URDF文件
        urdf_filename, _ = QFileDialog.getSaveFileName(self, "Save URDF file", "",
                                                       "URDF files (*.urdf);;All files (*.*)")
        if urdf_filename:
            try:
                self.tree.write(urdf_filename, encoding='utf-8', xml_declaration=True)
                QMessageBox.information(self, "Success", "URDF file saved successfully!")
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to save URDF: {str(e)}")



    def generate_yaml(self, suggested_filename=None):
        if not self.root:
            QMessageBox.warning(self, "Warning", "Please load a URDF file first!")
            return None  # 确保在没有加载URDF时返回None

        # 获取所有joints，只从ros2_control部分获取
        joints = []
        ros2_control = self.root.find(".//ros2_control")
        if ros2_control is not None:
            for joint in ros2_control.findall(".//joint"):
                joint_name = joint.get('name')
                if joint_name and joint_name not in joints:  # 避免重复
                    joints.append(joint_name)

        # 如果ros2_control中没有找到关节，则从普通joint标签中查找
        if not joints:
            for joint in self.root.findall(".//joint"):
                if joint.get('type') != 'fixed':  # 排除fixed类型的关节
                    joint_name = joint.get('name')
                    if joint_name and joint_name not in joints:  # 避免重复
                        joints.append(joint_name)

        yaml_content = {
            'controller_manager': {
                'ros__parameters': {
                    'update_rate': 1000,
                    'effort_controller': {
                        'type': 'effort_controllers/JointGroupEffortController'
                    },
                    'joint_state_broadcaster': {
                        'type': 'joint_state_broadcaster/JointStateBroadcaster'
                    }
                }
            },
            'effort_controller': {
                'ros__parameters': {
                    'joints': joints
                }
            }
        }

        # 保存YAML文件
        if suggested_filename:
            initial_filename = suggested_filename
        else:
            initial_filename = ""

        filename, _ = QFileDialog.getSaveFileName(self, "Save YAML file", initial_filename,
                                                  "YAML files (*.yaml);;All files (*.*)")
        if filename:
            try:
                with open(filename, 'w') as f:
                    yaml.dump(yaml_content, f, default_flow_style=False, sort_keys=False, indent=2)
                QMessageBox.information(self, "Success", "YAML file generated successfully!")
                return filename  # 返回保存的文件路径
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to save YAML: {str(e)}")
                return None
        return None  # 如果用户取消保存，返回None



def main():
    app = QApplication(sys.argv)
    editor = URDFEditor()
    editor.show()
    sys.exit(app.exec())

if __name__ == '__main__':
    main()
