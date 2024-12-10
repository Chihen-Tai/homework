#include <cstdlib> // 為 system 函數提供支持
#include <iostream>

int main() {
    std::cout << "Opening YouTube in your default browser..." << std::endl;

    // 指定要開啟的網址
    std::string url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

    // 將命令組合成字串
#ifdef _WIN32
    std::string command = "start " + url; // Windows 系統
#endif

    // 執行命令以打開瀏覽器
    int result = std::system(command.c_str());

    // 檢查命令是否成功執行
    if (result == 0) {
        std::cout << "YouTube opened successfully!" << std::endl;
    } else {
        std::cerr << "Failed to open YouTube." << std::endl;
    }

    return 0;
}
