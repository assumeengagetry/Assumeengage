import numpy as np

class KaomojiDB:
    def __init__(self):
        self.db = {
            "开心": ["(◍•ᴗ•◍)", "(｡♡‿♡｡)", "(*°▽°*)", "(≧▽≦)", "(◕‿◕✿)"],
            "伤心": ["(╥﹏╥)", "○|￣|_", "(╯︵╰,)", "(っ´ω｀c)", "(┬┬﹏┬┬)"],
            "生气": ["( ≧Д≦)", "(╬ Ò﹏Ó)", "o(>< )o", "ヽ(≧Д≦)ノ", "(＃｀д´)ﾉ"],
            "喜爱": ["(♡°▽°♡)", "♡(◡‿◡✿)", "(✿ ♡‿♡)", "( ´ ▽ ` ).｡ｏ♡", "(｡♥‿♥｡)"]
        }

    def get_kaomojis(self, category):
        return self.db[category]

    def get_categories(self):
        return list(self.db.keys())

    def add(self, category, kaomoji):
        self.db.setdefault(category, []).append(kaomoji)

    def has_category(self, category):
        return category in self.db

class KaomojiApp:
    def __init__(self):
        self.db = KaomojiDB()
        self.rng = np.random.default_rng()

    def run(self):
        while True:
            print("\n=== 颜文字生成器 ===")
            print("1. 随机生成")
            print("2. 按类别生成")
            print("3. 查看类别")
            print("4. 添加新颜文字")
            print("5. 退出")

            choice = input("请选择 (1-5): ")
            if not choice.isdigit() or not (1 <= int(choice) <= 5):
                print("输入无效！")
                continue

            choice = int(choice)
            if choice == 5:
                print("再见啦 (｀・ω・´)ノ")
                break

            self.handle_choice(choice)

    def handle_choice(self, choice):
        if choice == 1:
            self.handle_random_kaomoji()
        elif choice == 2:
            self.handle_category_kaomoji()
        elif choice == 3:
            self.handle_show_categories()
        elif choice == 4:
            self.handle_add_kaomoji()

    def handle_random_kaomoji(self):
        categories = self.db.get_categories()
        category = self.rng.choice(categories)
        print("随机生成的颜文字：", self.rng.choice(self.db.get_kaomojis(category)))

    def handle_category_kaomoji(self):
        category = input("请输入类别（开心/伤心/生气/喜爱）：")
        if not self.db.has_category(category):
            print("类别不存在！")
            return
        print("生成的颜文字：", self.rng.choice(self.db.get_kaomojis(category)))

    def handle_show_categories(self):
        print("可用类别：", " ".join(self.db.get_categories()))

    def handle_add_kaomoji(self):
        category = input("请输入类别：")
        kaomoji = input("请输入颜文字：")
        self.db.add(category, kaomoji)
        print("添加成功！")

if __name__ == "__main__":
    app = KaomojiApp()
    app.run()
#随便写的，不知道对不对，不过应该是这个意思吧