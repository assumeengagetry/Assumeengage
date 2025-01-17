#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <string_view>
#include <random>
#include <ctime>

using namespace std;

// 颜文字数据库管理类
class KaomojiDB {
private:
    unordered_map<string, vector<string>> db;

public:
    KaomojiDB() {
        db.reserve(10); // 预分配空间
        for (auto& category : db) {
            category.second.reserve(10);
        }
        
        db = {
            {"开心", {
                "(◍•ᴗ•◍)", "(｡♡‿♡｡)", "(*°▽°*)", "(≧▽≦)", "(◕‿◕✿)"
            }},
            {"伤心", {
                "(╥﹏╥)", "○|￣|_", "(╯︵╰,)", "(っ´ω｀c)", "(┬┬﹏┬┬)"
            }},
            {"生气", {
                "( ≧Д≦)", "(╬ Ò﹏Ó)", "o(>< )o", "ヽ(≧Д≦)ノ", "(＃｀д´)ﾉ"
            }},
            {"喜爱", {
                "(♡°▽°♡)", "♡(◡‿◡✿)", "(✿ ♡‿♡)", "( ´ ▽ ` ).｡ｏ♡", "(｡♥‿♥｡)"
            }}
        };
    }

    const vector<string>& get_kaomojis(string_view category) const {
        return db.at(string(category));
    }

    vector<string> get_categories() const {
        vector<string> categories;
        for (const auto& [key, _] : db) {
            categories.push_back(key);
        }
        return categories;
    }

    void add(const string& category, const string& kaomoji) {
        db[category].push_back(kaomoji);
    }

    bool has_category(const string& category) const {
        return db.find(category) != db.end();
    }
};

// 颜文字生成器
class KaomojiApp {
private:
    KaomojiDB db;
    mt19937 rng{random_device{}()};

    [[nodiscard]] inline string get_random_kaomoji(const vector<string>& list) const noexcept {
        uniform_int_distribution<> dist(0, list.size() - 1);
        return list[dist(rng)];
    }

public:
    void run() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        while (true) {
            cout << "\n=== 颜文字生成器 ===" << endl;
            cout << "1. 随机生成" << endl;
            cout << "2. 按类别生成" << endl;
            cout << "3. 查看类别" << endl;
            cout << "4. 添加新颜文字" << endl;
            cout << "5. 退出" << endl;
            
            int choice;
            cout << "请选择 (1-5): ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效！" << endl;
                continue;
            }

            // 根据选择执行相应操作
            handle_choice(choice);

            if (choice == 5) break;
        }
    }

private:
    void handle_choice(int choice) {
        switch (choice) {
            case 1:
                handle_random_kaomoji();
                break;
            case 2:
                handle_category_kaomoji();
                break;
            case 3:
                handle_show_categories();
                break;
            case 4:
                handle_add_kaomoji();
                break;
            case 5:
                cout << "再见啦 (｀・ω・´)ノ" << endl;
                break;
            default:
                cout << "无效选择！" << endl;
        }
    }

    void handle_random_kaomoji() {
        vector<string> categories = db.get_categories();
        string category = get_random_kaomoji(categories);
        cout << "随机生成的颜文字：" << get_random_kaomoji(db.get_kaomojis(category)) << endl;
    }

    void handle_category_kaomoji() {
        cout << "请输入类别（开心/伤心/生气/喜爱）：";
        string category;
        cin >> category;
        if (!db.has_category(category)) {
            cout << "类别不存在！" << endl;
            return;
        }
        cout << "生成的颜文字：" << get_random_kaomoji(db.get_kaomojis(category)) << endl;
    }

    void handle_show_categories() {
        cout << "可用类别：";
        for (const auto& category : db.get_categories()) {
            cout << category << " ";
        }
        cout << endl;
    }

    void handle_add_kaomoji() {
        string category, kaomoji;
        cout << "请输入类别：";
        cin >> category;
        cout << "请输入颜文字：";
        cin.ignore();
        getline(cin, kaomoji);
        db.add(category, kaomoji);
        cout << "添加成功！" << endl;
    }
};

// 编译命令：g++ -O3 -march=native -flto main.cpp -o kaomoji
int main() {
    KaomojiApp app;
    app.run();
    return 0;
}