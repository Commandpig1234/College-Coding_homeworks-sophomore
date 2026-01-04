import os
import shutil

# ========= 1. 在这里修改名称列表 =========
names = [
    "graph_BreadthFirst",
    "project_CriticalRoute",
    "maze_Problem",
    "connected_Graph",
]

# ========= 2. 路径设置（基于程序所在目录） =========
# Wheels 目录
WHEELS_DIR = os.path.dirname(os.path.abspath(__file__))

# C-CODE 目录
ROOT_DIR = os.path.dirname(WHEELS_DIR)

# Z_DS3 目录
Z_DS3_DIR = os.path.join(ROOT_DIR, "Z_DS3")

# input 目录
INPUT_DIR = os.path.join(Z_DS3_DIR, "input")

# frame.cpp 路径
FRAME_CPP = os.path.join(WHEELS_DIR, "frame.cpp")

# ========= 3. 基本检查 =========
if not os.path.isfile(FRAME_CPP):
    raise FileNotFoundError(f"未找到模板文件: {FRAME_CPP}")

os.makedirs(Z_DS3_DIR, exist_ok=True)
os.makedirs(INPUT_DIR, exist_ok=True)

# ========= 4. 批量创建文件 =========
for name in names:
    cpp_path = os.path.join(Z_DS3_DIR, f"{name}.cpp")
    txt_path = os.path.join(INPUT_DIR, f"{name}.txt")

    # 复制 frame.cpp -> 名称.cpp
    shutil.copyfile(FRAME_CPP, cpp_path)

    # 创建（或覆盖）名称.txt
    with open(txt_path, "w", encoding="utf-8") as f:
        pass

    print(f"已生成: {cpp_path}")
    print(f"已生成: {txt_path}")

print("全部文件生成完成。")
