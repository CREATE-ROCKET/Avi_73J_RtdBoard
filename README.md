# Avi_73J_Board

## システム構成

## RTD基板システム要件
### 各基板とのつながり
```mermaid
graph TD
    subgraph ジンバル基板
        D[ジンバル送信]
        A[ジンバル受信]
    end
    subgraph RTD基板
        B[RTD送信]
        E[RTD受信]
    end
    subgraph 地上
        F[地上受信]
        C[地上送信]
    end
    D -->|コマンドとデータ| E  
    B -->|コマンド| A
    B -->|コマンドとデータ| F
    C -->|コマンド| E
```

### RTD基板の仕様
```mermaid
graph TD
    subgraph CPU0
        B
        C
        F
        G
        K
        N
        D
        E
        M
    end
    subgraph CPU1
        H
        I
        J
    end
    A[電源ON] --> B(地上からのコマンド受信)
    A --> C(ジンバルからのコマンド受信)
    B --> |コマンド'***'| D[記録&データ送信開始]
    B --> |コマンド'***'| E[ジンバルスタート]
    E --> G(ジンバルにコマンド'***'を送信)
    D --> F(ジンバルにコマンド'***'を送信)
    D --> H(加速度データを取る)
    H --> I(気圧データを取る)
    I --> J(Flashに書き込む)
    I --> K(地上に送信)
    J --> L(繰り返す 加速度データを取るところに戻る)
    K --> L
    C --> |コマンド'***'| M[ジンバルデータ受信開始]
    M --> N(データ受け取る)
    N --> K
```

### 実装 
