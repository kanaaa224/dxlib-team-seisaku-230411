/********************************
* ランキング画面
********************************/
void DrawRanking(void) {

    // スペースキーでメニューに戻る
    if (gKeyFlg & PAD_INPUT_M) gGameMode = TITLE;

    // ランキング画面表示
    DrawGraph(0, 0, gRankingImg, FALSE);

    // ランキング一覧を表示
    SetFontSize(18);
    for (int i = 0; i < RANKING_DATA; i++) {
        DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d", gRanking[i].no, gRanking[i].name, gRanking[i].score);
    };

    DrawString(100, 450, "--- スペースキーを押してタイトルへ戻る ---", 0xff0000, 0);
};

/********************************
* ランキング入力処理
********************************/
void InputName(void) {

    // ランキング画像表示
    DrawGraph(0, 0, gTitleImg, FALSE);

    // フォントサイズの設定
    SetFontSize(20);

    // 名前入力指示文字列の描画
    DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
    DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

    // 名前入力
    DrawString(150, 310, "> ", 0xFFFFFF);
    DrawBox(160, 305, 300, 335, 0x000055, TRUE);
    if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE) == 1) {
        gRanking[RANKING_DATA - 1].score = gScore; // ランキングデータにスコア登録
        SortRanking(); // ランキング並び替え
        SaveRanking(); // ランキング保存
        gGameMode = RANKING; // ゲームモード変更
    };
    //gGameMode = TITLE;
};

/********************************
* ランキング並び替え
********************************/
void SortRanking(void) {
    int i, j;
    RankingData work;

    // 選択法ソート
    for (i = 0; i < RANKING_DATA - 1; i++) {
        for (j = i + 1; j < RANKING_DATA; j++) {
            if (gRanking[i].score <= gRanking[j].score) {
                work = gRanking[i];
                gRanking[i] = gRanking[j];
                gRanking[j] = work;
            };
        };
    };

    // 順位付け
    for (i = 0; i < RANKING_DATA; i++) {
        gRanking[i].no = 1;
    };
    // 得点が同じ場合は同じ順位とする
    // 同順位があった場合の次の順位はデータ個数が加算された順位とする
    for (i = 0; i < RANKING_DATA - 1; i++) {
        for (j = i + 1; j < RANKING_DATA; j++) {
            if (gRanking[i].score > gRanking[j].score) {
                gRanking[j].no++;
            };
        };
    };
};

/********************************
* ランキング保存
********************************/
int SaveRanking(void) {
    FILE* fp;
#pragma warning(disable:4996)

    // ファイルオープン
    if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
        // エラー処理
        printf("Ranking Data Error\n");
        return -1;
    };
    // ランキングデータ分配列データを書き込む
    for (int i = 0; i < RANKING_DATA; i++) {
        fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
    };

    // ファイルクローズ
    fclose(fp);
    return 0;
};

/********************************
* ランキング読み込み
********************************/
int ReadRanking(void) {
    FILE* fp;
#pragma warningI(disable:4996)

    // ファイルオープン
    if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
        // エラー処理
        printf("Ranking Data Error\n");
        return -1;
    };
    // ランキングデータ分配列データを読み込む
    for (int i = 0; i < RANKING_DATA; i++) {
        int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
    };

    // ファイルクローズ
    fclose(fp);
    return 0;
};