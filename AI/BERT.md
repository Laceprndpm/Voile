# BERT

## 标题

**Pre-training of Deep Bidirectional Transformers for Language Understanding**

- “Language Understanding” 强调的是**判别/理解类任务的统一底座**（分类、蕴含、序列标注、QA 等），不局限于翻译这种 seq2seq 生成任务。
- BERT 的核心不是“把 Transformer 用在 NLP”，而是：**用 Transformer Encoder 做深层双向表征 + 预训练目标设计 + 端到端微调范式**。

------

## 摘要（你抓得对，但可以再补一句“为什么重要”）

> deep bidirectional representations … conditioning on both left and right context in all layers

- “deep bidirectional” 的重点是：**每一层**都能同时看左右上下文（不是像 ELMo 那种把两个方向在顶层拼起来的“浅层融合”）。

> fine-tuned with just one additional output layer …

- 这句话的范式含义是：BERT 把迁移学习从“feature-based（抽特征）”推向“fine-tuning（同一个骨干直接端到端微调）”，大幅降低下游结构工程。

------

## 导言（你写的“都是单向的”需要更精准）

BERT 提到当时两类主流迁移策略：

- **Feature-based**：如 ELMo，预训练得到表征，然后下游模型自己再做一套结构。
- **Fine-tuning**：如 GPT（当时），预训练后整个模型端到端微调，但 GPT 是**自回归单向**。

需要更准确的一句：

- 不是说“所有方法都单向”，而是说：
  - GPT 这类 fine-tuning 方法是单向；
  - ELMo 是双向但多为 feature-based 用法，且双向融合方式不同；
  - 作者想要：**双向 + 端到端微调** 两者兼得。

然后他们提出：

- **MLM（Masked Language Model）**：随机遮住词，让模型利用左右上下文预测被遮住的 token，从而实现“可训练的双向”。
- **NSP（Next Sentence Prediction）**：训练句子间关系（是否为原文相邻句），用于句对任务（NLI、QA 等）。

------

## BERT 模型（这里是你最需要“加细节”的部分）

### 结构（你写“seq2seq结构没有介绍”这里建议改）

BERT 使用的是 **Transformer Encoder 堆叠**（不是 seq2seq 的 encoder-decoder）。

- **Encoder-only**：输入整段序列，输出每个 token 的上下文化向量。
- “双向”来自：Encoder 的 self-attention 不做因果 mask（可以看全序列）。

常用两种规模（论文里）：

- **BERT_BASE**: 12 层，hidden 768，12 heads，约 110M 参数
- **BERT_LARGE**: 24 层，hidden 1024，16 heads，约 340M 参数

（你写笔记时不一定要记数字，但可以记“BASE/LARGE 两档”这个事实。）

------

### 输入表示（你已经写了一部分，可以组织得更像论文）

BERT 的输入 embedding 是三部分相加：

1. **Token embedding**（WordPiece 词表）
2. **Position embedding**（可学习位置向量）
3. **Segment embedding（A/B）**：标记 token 属于句子 A 还是句子 B（用于句对）

并且引入两个特殊 token：

- **[CLS]**：放在序列开头，作为“句级表示”的聚合位（分类任务常用它）
- **[SEP]**：句子分隔符；单句任务也会在末尾加一个 [SEP]

你写的 WordPiece 例子很好：`flightless → flight ##less`
可以补一句它的目的：**降低 OOV、用子词共享统计强度**。

------

### 预训练目标（你写得对，但可补“MLM细节 + 为什么要NSP”）

#### 目标 1：Masked Language Model（MLM）

- 从输入 token 中随机选 **15%** 做预测目标（prediction targets）
- 对这些被选中的位置：
  - **80% 替换为 [MASK]**
  - **10% 替换为随机 token**
  - **10% 保持原样**
- 训练时只对这 15% 的位置计算 loss（交叉熵）

你提到“因为微调没有 mask 会有问题，所以这样做”，这个理由是对的：
这是为了减少 **pretrain-finetune mismatch**（预训练看到 [MASK]，微调却看不到）的分布差异。

#### 目标 2：Next Sentence Prediction（NSP）

- 构造句对 (A, B)：
  - 50%：B 是 A 的下一句（IsNext）
  - 50%：B 是语料中随机抽取（NotNext）
- 用 [CLS] 的输出做二分类

你已经给了例子，很棒。可以再补一句作者当时的动机：
**让模型学到跨句关系**，更适合 NLI/QA 这种句对任务。

------

### 微调（这里补“不同任务怎么接头”最有用）

微调时不再使用 [MASK] 机制，输入是真实文本，端到端更新参数。

常见下游任务接证明：

- **句子分类 / 句对分类（NLI 等）**：取 `[CLS]` 的向量 → 接一个线性层分类
- **序列标注（NER 等）**：对每个 token 的输出向量接分类层
- **抽取式 QA（SQuAD）**：对每个 token 预测“起点概率”和“终点概率”（两个线性层输出 start/end logits）

> 你笔记里“只加一个小头”是对的，补上这三类任务的接法，你的“理解”就很完整了。

------

## 实验（你写略也行，但建议至少补 2 句“证据形式”）

你不想写数值完全 OK，但建议加：

- 覆盖了 **句级任务、句对任务、token 级任务、QA** 等多类 benchmark；
- BERT_LARGE 在多个任务上达到当时 SOTA，尤其在句对与 QA 类任务上优势显著（体现双向表征的价值）。

------

## 评论（你写“添加更多细节”，我建议你写成 3 条“读完你自己的观点”）

### 它相对 ELMo / GPT 的“真正新点”

- **不是简单 ELMo+GPT**，而是：
  - 用 **Transformer Encoder** 做“深层双向”
  - 用 **MLM** 让双向训练可行
  - 把迁移范式主推为**端到端微调**（比 ELMo 的 feature-based 更统一）

### 局限（写一两条就够）

- **[MASK] 与真实输入不一致**仍然存在（虽然 80/10/10 缓解，但没有消失）
- **NSP 后来被不少工作质疑有效性**（你可以记个“后来很多模型去掉 NSP”作为后续线索）
- 以及：encoder-only 更偏判别任务；做生成需要额外 decoder 或改造

### 对你做蒸馏/压缩最有用的点

BERT 之所以对压缩领域特别重要，是因为它后来催生了非常多经典路线：

- **DistilBERT / TinyBERT / MobileBERT** 这类“把大 BERT 蒸馏到小模型”的范式几乎成了 NLP 压缩教科书模板
  你以后读压缩论文，会反复看到：MLM 蒸馏、layer dropping、attention/head 剪枝、量化等都先在 BERT 上打样。

