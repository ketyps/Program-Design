#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 定义系统常量
#define MAX_QUESTIONS 100    // 最大题目数量
#define MAX_STUDENTS 100     // 最大考生数量

// 题目结构体：存储每道题的所有信息
typedef struct {
    int id;                     // 题目编号（从1开始）
    char type[10];              // 题型：选择题/判断题
    char question[200];         // 题目内容
    char options[4][100];       // 选项（仅选择题使用，最多4个选项）
    char answer[10];            // 正确答案
    int score;                  // 题目分值
} Question;

// 考生结构体：存储每个考生的信息和答题情况
typedef struct {
    char id[20];                // 学号
    char name[20];              // 姓名
    char answers[MAX_QUESTIONS][10];  // 考生答案数组
    int scores[MAX_QUESTIONS];  // 每题得分数组
    int totalScore;             // 考试总分
} Student;

// 试卷结构体：包含所有题目
typedef struct {
    Question questions[MAX_QUESTIONS];  // 题目数组
    int questionCount;           // 当前题目数量
    int maxScore;               // 试卷总分
} Paper;

// 考试系统结构体：系统的核心数据结构
typedef struct {
    Paper paper;                // 试卷对象
    Student students[MAX_STUDENTS]; // 考生数组
    int studentCount;           // 已参加考试的考生数量
    struct tm examStart;        // 考试开始时间（年月日时分秒）
    struct tm examEnd;          // 考试结束时间
    int examDuration;           // 考试时长（分钟）
    int examTimeSet;            // 标志位：考试时间是否已设置（0未设置，1已设置）
} ExamSystem;

// 函数声明区域
void initSystem(ExamSystem *sys);          // 初始化系统
void showMenu();                           // 显示主菜单
void addQuestion(ExamSystem *sys);         // 添加题目
void showQuestions(ExamSystem *sys);       // 显示所有题目
void deleteQuestion(ExamSystem *sys);      // 删除题目
void takeExam(ExamSystem *sys);            // 开始考试
void showResults(ExamSystem *sys);         // 查看成绩
void analyzeScores(ExamSystem *sys);       // 成绩统计分析
void checkTime(ExamSystem *sys);           // 检查考试时间
void setExamTime(ExamSystem *sys);         // 设置考试时间
int isExamTime(ExamSystem *sys);           // 检查是否在考试时间内
void parseDateTime(const char *datetime, struct tm *tm); // 解析日期时间字符串
void displayDateTime(struct tm *tm);       // 显示日期时间
time_t tmToTime(struct tm *tm);            // tm结构体转time_t

// 主函数：程序入口
int main() {
    ExamSystem sys;              // 创建考试系统对象
    initSystem(&sys);            // 初始化系统
    
    int choice;                  // 用户菜单选择
    
    // 主循环：持续显示菜单并处理用户选择，直到选择退出
    while(1) {
        showMenu();              // 显示菜单
        printf("请选择功能: ");
        scanf("%d", &choice);    // 获取用户选择
        
        // 根据用户选择执行相应功能
        switch(choice) {
            case 1:
                addQuestion(&sys);      // 录入题目
                break;
            case 2:
                showQuestions(&sys);    // 查看题目
                break;
            case 3:
                deleteQuestion(&sys);   // 删除题目
                break;
            case 4:
                setExamTime(&sys);      // 设置考试时间
                break;
            case 5:
                takeExam(&sys);         // 开始考试
                break;
            case 6:
                showResults(&sys);      // 查看成绩
                break;
            case 7:
                analyzeScores(&sys);    // 成绩统计
                break;
            case 8:
                checkTime(&sys);        // 检查考试时间
                break;
            case 9:
                printf("谢谢使用，再见！\n");
                return 0;               // 退出程序
            default:
                printf("输入错误，请重新选择！\n");
        }
    }
    
    return 0;
}

// 初始化系统：设置默认值，添加示例题目
void initSystem(ExamSystem *sys) {
    // 初始化基本数据
    sys->paper.questionCount = 0;  // 初始题目数量为0
    sys->studentCount = 0;         // 初始考生数量为0
    sys->paper.maxScore = 0;       // 初始试卷总分为0
    sys->examTimeSet = 0;          // 考试时间未设置
    
    // 设置默认考试时间（当前时间开始，2小时后结束）
    time_t now = time(NULL);               // 获取当前时间
    struct tm *tm_now = localtime(&now);   // 转换为本地时间结构体
    
    // 设置考试开始时间为当前时间
    sys->examStart = *tm_now;
    
    // 设置考试结束时间为2小时后
    sys->examEnd = *tm_now;
    sys->examEnd.tm_hour += 2;             // 小时加2
    
    // 处理时间溢出（超过24小时）
    if (sys->examEnd.tm_hour >= 24) {
        sys->examEnd.tm_hour -= 24;        // 调整小时
        sys->examEnd.tm_mday += 1;         // 天数加1
    }
    
    sys->examDuration = 120;               // 考试时长120分钟（2小时）
    
    // 添加示例题目，方便测试
    Question q1 = {1, "选择", "C语言中，以下哪个是合法的标识符？",
        {"A. 2test", "B. test-1", "C. _test", "D. break"}, "C", 5};
    Question q2 = {2, "判断", "C语言是面向对象的语言。", {}, "错误", 5};
    Question q3 = {3, "选择", "以下哪个用于输出字符？",
        {"A. printf()", "B. scanf()", "C. getchar()", "D. putchar()"}, "D", 5};
    
    // 将示例题目添加到试卷中
    sys->paper.questions[sys->paper.questionCount++] = q1;
    sys->paper.questions[sys->paper.questionCount++] = q2;
    sys->paper.questions[sys->paper.questionCount++] = q3;
    sys->paper.maxScore = 15;  // 计算试卷总分：5+5+5=15
    
    printf("系统初始化完成！已添加3道示例题目。\n");
}

// 显示主菜单：系统功能选择界面
void showMenu() {
    printf("\n======= 简单考试系统 =======\n");
    printf("1. 录入题目\n");
    printf("2. 查看题目\n");
    printf("3. 删除题目\n");
    printf("4. 设置考试时间\n");
    printf("5. 开始考试\n");
    printf("6. 查看成绩\n");
    printf("7. 成绩统计\n");
    printf("8. 检查考试时间\n");
    printf("9. 退出系统\n");
    printf("=============================\n");
}

// 录入题目：向试卷中添加新题目
void addQuestion(ExamSystem *sys) {
    // 检查题目数量是否已达上限
    if(sys->paper.questionCount >= MAX_QUESTIONS) {
        printf("题目数量已达上限（%d题）！无法继续添加。\n", MAX_QUESTIONS);
        return;
    }
    
    Question q;                    // 创建新题目对象
    q.id = sys->paper.questionCount + 1;  // 设置题目编号
    
    printf("\n=== 录入题目 ===\n");
    printf("请选择题型（1.选择题 2.判断题）：");
    int typeChoice;
    scanf("%d", &typeChoice);
    getchar();  // 清除输入缓冲区中的换行符
    
    // 根据用户选择设置题型
    if(typeChoice == 1) {
        strcpy(q.type, "选择");
        
        printf("请输入题目内容：");
        fgets(q.question, sizeof(q.question), stdin);
        q.question[strlen(q.question)-1] = '\0';  // 去掉末尾的换行符
        
        // 录入选择题的四个选项
        printf("请输入选项A：");
        fgets(q.options[0], sizeof(q.options[0]), stdin);
        q.options[0][strlen(q.options[0])-1] = '\0';
        
        printf("请输入选项B：");
        fgets(q.options[1], sizeof(q.options[1]), stdin);
        q.options[1][strlen(q.options[1])-1] = '\0';
        
        printf("请输入选项C：");
        fgets(q.options[2], sizeof(q.options[2]), stdin);
        q.options[2][strlen(q.options[2])-1] = '\0';
        
        printf("请输入选项D：");
        fgets(q.options[3], sizeof(q.options[3]), stdin);
        q.options[3][strlen(q.options[3])-1] = '\0';
        
        printf("请输入正确答案（A/B/C/D）：");
        scanf("%s", q.answer);
    } else {
        // 判断题处理
        strcpy(q.type, "判断");
        
        printf("请输入题目内容：");
        fgets(q.question, sizeof(q.question), stdin);
        q.question[strlen(q.question)-1] = '\0';
        
        printf("请输入正确答案（正确/错误）：");
        scanf("%s", q.answer);
    }
    
    printf("请输入分值：");
    scanf("%d", &q.score);
    getchar();  // 清除换行符
    
    // 将题目添加到试卷中
    sys->paper.questions[sys->paper.questionCount++] = q;
    sys->paper.maxScore += q.score;  // 更新试卷总分
    printf("题目添加成功！当前题目数量：%d，试卷总分：%d\n", 
           sys->paper.questionCount, sys->paper.maxScore);
}

// 查看题目：显示试卷中的所有题目
void showQuestions(ExamSystem *sys) {
    if(sys->paper.questionCount == 0) {
        printf("当前没有题目！请先录入题目。\n");
        return;
    }
    
    printf("\n=== 试卷题目（共%d题，总分%d）===\n", 
           sys->paper.questionCount, sys->paper.maxScore);
    
    // 遍历所有题目并显示详细信息
    for(int i = 0; i < sys->paper.questionCount; i++) {
        Question q = sys->paper.questions[i];
        printf("\n题目%d [%s题]（分值：%d）\n", q.id, q.type, q.score);
        printf("题目内容：%s\n", q.question);
        
        // 如果是选择题，显示所有选项
        if(strcmp(q.type, "选择") == 0) {
            for(int j = 0; j < 4; j++) {
                printf("  %s\n", q.options[j]);
            }
        }
        
        printf("正确答案：%s\n", q.answer);
    }
}

// 删除题目：从试卷中删除指定题目
void deleteQuestion(ExamSystem *sys) {
    // 检查试卷是否为空
    if(sys->paper.questionCount == 0) {
        printf("当前没有题目！无法删除。\n");
        return;
    }
    
    // 先显示所有题目，让用户知道有哪些题目
    showQuestions(sys);
    
    int delId;
    printf("\n请输入要删除的题目编号（1-%d）：", sys->paper.questionCount);
    scanf("%d", &delId);
    
    // 验证题目编号是否有效
    if(delId < 1 || delId > sys->paper.questionCount) {
        printf("题目编号无效！请输入1-%d之间的数字。\n", sys->paper.questionCount);
        return;
    }
    
    // 调整试卷总分：减去被删除题目的分值
    sys->paper.maxScore -= sys->paper.questions[delId-1].score;
    
    // 移动后面的题目，覆盖要删除的题目
    for(int i = delId-1; i < sys->paper.questionCount-1; i++) {
        sys->paper.questions[i] = sys->paper.questions[i+1];
        sys->paper.questions[i].id = i + 1;  // 重新编号
    }
    
    sys->paper.questionCount--;  // 题目数量减1
    printf("题目删除成功！剩余题目数量：%d，试卷总分：%d\n", 
           sys->paper.questionCount, sys->paper.maxScore);
}

// 设置考试时间：允许用户指定考试的起止时间
void setExamTime(ExamSystem *sys) {
    printf("\n=== 设置考试时间 ===\n");
    
    char startTime[20], endTime[20];  // 存储用户输入的时间字符串
    
    printf("请输入考试开始时间（格式：YYYY-MM-DD HH:MM）\n");
    printf("例如：2024-06-01 09:00\n");
    printf("开始时间：");
    getchar();  // 清除之前的换行符
    fgets(startTime, sizeof(startTime), stdin);
    startTime[strlen(startTime)-1] = '\0';  // 去掉换行符
    
    printf("请输入考试结束时间（格式：YYYY-MM-DD HH:MM）\n");
    printf("例如：2024-06-01 11:00\n");
    printf("结束时间：");
    fgets(endTime, sizeof(endTime), stdin);
    endTime[strlen(endTime)-1] = '\0';
    
    // 解析用户输入的时间字符串
    parseDateTime(startTime, &sys->examStart);
    parseDateTime(endTime, &sys->examEnd);
    
    // 计算考试时长（分钟）
    time_t start = tmToTime(&sys->examStart);
    time_t end = tmToTime(&sys->examEnd);
    sys->examDuration = (int)difftime(end, start) / 60;
    
    sys->examTimeSet = 1;  // 标记考试时间已设置
    
    // 显示设置结果
    printf("\n考试时间设置成功！\n");
    printf("考试开始时间：");
    displayDateTime(&sys->examStart);
    printf("\n考试结束时间：");
    displayDateTime(&sys->examEnd);
    printf("\n考试时长：%d分钟\n", sys->examDuration);
}

// 解析日期时间字符串：将字符串转换为tm结构体
void parseDateTime(const char *datetime, struct tm *tm) {
    memset(tm, 0, sizeof(struct tm));  // 清空结构体
    
    // 使用sscanf解析格式化的日期时间字符串
    sscanf(datetime, "%d-%d-%d %d:%d",
           &tm->tm_year, &tm->tm_mon, &tm->tm_mday,
           &tm->tm_hour, &tm->tm_min);
    
    // tm结构体的特殊处理：年份从1900开始，月份从0开始
    tm->tm_year -= 1900;  // 年份减去1900
    tm->tm_mon -= 1;      // 月份减去1（因为tm_mon的范围是0-11）
    tm->tm_sec = 0;       // 秒数设为0（因为用户只输入到分钟）
}

// 显示日期时间：将tm结构体格式化为可读字符串并输出
void displayDateTime(struct tm *tm) {
    printf("%04d-%02d-%02d %02d:%02d:%02d",
           tm->tm_year + 1900,  // 年份加回1900
           tm->tm_mon + 1,      // 月份加回1
           tm->tm_mday,         // 日
           tm->tm_hour,         // 时
           tm->tm_min,          // 分
           tm->tm_sec);         // 秒
}

// tm结构体转换为time_t：用于时间比较和计算
time_t tmToTime(struct tm *tm) {
    struct tm tm_copy = *tm;  // 创建副本，防止修改原结构体
    return mktime(&tm_copy);  // 转换为time_t类型
}

// 开始考试：考生登录并答题
void takeExam(ExamSystem *sys) {
    // 检查考试时间是否已设置
    if(!sys->examTimeSet) {
        printf("请先设置考试时间！\n");
        return;
    }
    
    // 检查当前是否在考试时间内
    if(!isExamTime(sys)) {
        printf("当前不在考试时间内！\n");
        checkTime(sys);  // 显示时间信息
        return;
    }
    
    // 检查考生数量是否已达上限
    if(sys->studentCount >= MAX_STUDENTS) {
        printf("考生数量已达上限（%d人）！\n", MAX_STUDENTS);
        return;
    }
    
    printf("\n=== 开始考试 ===\n");
    
    // 考生登录：获取学号和姓名
    Student stu;  // 创建考生对象
    printf("请输入学号：");
    scanf("%s", stu.id);
    printf("请输入姓名：");
    scanf("%s", stu.name);
    
    stu.totalScore = 0;  // 初始化总分为0
    
    // 开始答题
    printf("\n请开始答题（每道题请在60秒内完成）：\n");
    printf("注意：考试时间结束后将自动交卷！\n");
    
    // 遍历试卷中的每道题目
    for(int i = 0; i < sys->paper.questionCount; i++) {
        Question q = sys->paper.questions[i];
        
        printf("\n题目%d [%s题]（分值：%d）\n", q.id, q.type, q.score);
        printf("题目：%s\n", q.question);
        
        // 如果是选择题，显示选项
        if(strcmp(q.type, "选择") == 0) {
            for(int j = 0; j < 4; j++) {
                printf("  %s\n", q.options[j]);
            }
            printf("请输入答案（A/B/C/D）：");
        } else {
            printf("请输入答案（正确/错误）：");
        }
        
        // 检查考试时间是否已结束
        if(!isExamTime(sys)) {
            printf("\n考试时间已结束！自动交卷。\n");
            break;  // 退出答题循环
        }
        
        // 答题计时开始
        time_t startTime = time(NULL);
        printf("你有60秒答题时间，请尽快作答...\n");
        
        // 获取考生答案
        scanf("%s", stu.answers[i]);
        
        // 检查是否超时
        if(difftime(time(NULL), startTime) > 60) {
            printf("答题超时！本题得0分\n");
            stu.scores[i] = 0;  // 超时得0分
        } else {
            // 评分：比较考生答案和正确答案
            if(strcmp(stu.answers[i], q.answer) == 0) {
                stu.scores[i] = q.score;          // 答对得满分
                stu.totalScore += q.score;        // 累加总分
                printf("回答正确！\n");
            } else {
                stu.scores[i] = 0;                // 答错得0分
                printf("回答错误！正确答案是：%s\n", q.answer);
            }
        }
    }
    
    // 保存考生信息到系统
    sys->students[sys->studentCount++] = stu;
    
    // 显示考试结果
    printf("\n考试结束！\n");
    printf("考生：%s（%s）\n", stu.name, stu.id);
    printf("总分：%d/%d\n", stu.totalScore, sys->paper.maxScore);
}

// 查看成绩：显示所有考生的成绩详情
void showResults(ExamSystem *sys) {
    if(sys->studentCount == 0) {
        printf("暂无考生成绩！请先进行考试。\n");
        return;
    }
    
    printf("\n=== 考试成绩（共%d名考生）===\n", sys->studentCount);
    
    // 遍历所有考生
    for(int i = 0; i < sys->studentCount; i++) {
        Student stu = sys->students[i];
        printf("\n考生%d：%s（学号：%s）\n", i+1, stu.name, stu.id);
        printf("总分：%d/%d（得分率：%.1f%%）\n", 
               stu.totalScore, sys->paper.maxScore,
               (float)stu.totalScore/sys->paper.maxScore*100);
        
        printf("详细答题情况：\n");
        // 显示每道题的答题情况
        for(int j = 0; j < sys->paper.questionCount; j++) {
            printf("  题目%d：你的答案：%s，得分：%d/%d\n", 
                   j+1, stu.answers[j], stu.scores[j], 
                   sys->paper.questions[j].score);
        }
    }
}

// 成绩统计分析：计算各种统计指标
void analyzeScores(ExamSystem *sys) {
    if(sys->studentCount == 0) {
        printf("暂无考生成绩！请先进行考试。\n");
        return;
    }
    
    int sum = 0;                       // 总分累加
    int max = 0;                       // 最高分
    int min = sys->paper.maxScore;     // 最低分（初始化为满分）
    int passCount = 0;                 // 及格人数
    int excellentCount = 0;            // 优秀人数（80分以上）
    
    printf("\n=== 成绩统计分析（共%d名考生）===\n", sys->studentCount);
    
    // 第一轮遍历：计算总分、最高分、最低分
    for(int i = 0; i < sys->studentCount; i++) {
        int score = sys->students[i].totalScore;
        sum += score;  // 累加总分
        
        // 更新最高分
        if(score > max) {
            max = score;
        }
        
        // 更新最低分
        if(score < min) {
            min = score;
        }
        
        // 统计及格人数（60%以上）
        if(score >= sys->paper.maxScore * 0.6) {
            passCount++;
        }
        
        // 统计优秀人数（80%以上）
        if(score >= sys->paper.maxScore * 0.8) {
            excellentCount++;
        }
    }
    
    // 计算统计指标
    float avg = (float)sum / sys->studentCount;                     // 平均分
    float passRate = (float)passCount / sys->studentCount * 100;    // 及格率
    float excellentRate = (float)excellentCount / sys->studentCount * 100;  // 优秀率
    
    // 输出统计分析结果
    printf("平均分：%.2f\n", avg);
    printf("最高分：%d\n", max);
    printf("最低分：%d\n", min);
    printf("及格人数：%d（%.1f%%）\n", passCount, passRate);
    printf("优秀人数：%d（%.1f%%）\n", excellentCount, excellentRate);
    printf("试卷总分：%d\n", sys->paper.maxScore);
    
    // 打印成绩单（按分数降序排列）
    printf("\n=== 成绩单（按分数从高到低）===\n");
    
    // 创建考生索引数组用于排序
    int indices[MAX_STUDENTS];
    for(int i = 0; i < sys->studentCount; i++) {
        indices[i] = i;
    }
    
    // 冒泡排序：按分数降序排列
    for(int i = 0; i < sys->studentCount - 1; i++) {
        for(int j = 0; j < sys->studentCount - 1 - i; j++) {
            if(sys->students[indices[j]].totalScore < sys->students[indices[j+1]].totalScore) {
                // 交换索引
                int temp = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = temp;
            }
        }
    }
    
    // 输出排序后的成绩单
    for(int i = 0; i < sys->studentCount; i++) {
        int idx = indices[i];
        printf("%d. %s（学号：%s）：%d分（排名：%d）\n", 
               i+1, 
               sys->students[idx].name, 
               sys->students[idx].id, 
               sys->students[idx].totalScore,
               i+1);
    }
}

// 检查考试时间：显示当前时间和考试时间信息
void checkTime(ExamSystem *sys) {
    // 检查考试时间是否已设置
    if(!sys->examTimeSet) {
        printf("请先设置考试时间！\n");
        return;
    }
    
    time_t now = time(NULL);                  // 获取当前时间
    time_t start = tmToTime(&sys->examStart); // 考试开始时间
    time_t end = tmToTime(&sys->examEnd);     // 考试结束时间
    
    printf("\n=== 考试时间信息 ===\n");
    printf("当前系统时间：%s", ctime(&now));  // ctime自动添加换行符
    printf("考试开始时间：");
    displayDateTime(&sys->examStart);
    printf("\n考试结束时间：");
    displayDateTime(&sys->examEnd);
    printf("\n考试时长：%d分钟\n", sys->examDuration);
    
    // 计算时间差
    double remaining = difftime(end, now);    // 距离结束的秒数
    double untilStart = difftime(start, now); // 距离开始的秒数
    
    if(remaining > 0) {
        if(untilStart > 0) {
            // 考试尚未开始
            printf("状态：考试尚未开始\n");
            printf("距离考试开始还有：%.0f分钟\n", untilStart/60);
        } else {
            // 考试正在进行
            printf("状态：考试正在进行中\n");
            printf("已进行：%.0f分钟\n", difftime(now, start)/60);
            printf("剩余时间：%.0f分钟\n", remaining/60);
        }
    } else {
        // 考试已结束
        printf("状态：考试已结束\n");
        printf("考试结束已过去：%.0f分钟\n", -remaining/60);
    }
}

// 检查是否在考试时间内：返回1表示在考试时间内，0表示不在
int isExamTime(ExamSystem *sys) {
    // 如果考试时间未设置，返回不在考试时间
    if(!sys->examTimeSet) {
        return 0;
    }
    
    time_t now = time(NULL);                  // 当前时间
    time_t start = tmToTime(&sys->examStart); // 考试开始时间
    time_t end = tmToTime(&sys->examEnd);     // 考试结束时间
    
    // 检查当前时间是否在考试开始和结束时间之间
    return (now >= start && now <= end);
}
