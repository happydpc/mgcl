# 幾何オブジェクト #



## 概要 ##

`MGGeometry` は `MGPoint`, `MGCurve`, `MGSurface` のスーパークラスで抽象クラスです。

![http://mgcl.googlecode.com/svn/wiki/image/mg-geometry.png](http://mgcl.googlecode.com/svn/wiki/image/mg-geometry.png)

異なる多様体次元に対応できる共通関数が用意されています。

  * あるパラメータにおける任意の回数の微分値を求める。
  * 空間次元を求める。
  * ボックス枠を求める。
  * 多様体次元を求める (点、線、面の区分を得る)。
  * オブジェクトのクローンを生成する。
  * ある点の乗っている Geometry のパラメータ値を得る。
  * スケーリング、ベクター、マトリックス、一般変換による座標変換を行う 。
  * 方向を逆転させる。

### 点と曲線／曲面の関係 ###

`on`, `param` メンバー関数:

> `on`, `param` は点 (`MGPosition`) と 線 (`MGCurve`) または, 面 (`MGSurface`) との関係で、
> 曲線、曲面が与えられた点のデータとなるパラメータ値を求める。

`closest` メンバー関数;

> `closest` は点から曲線／曲面へ最も近い点を曲線／曲面のパラメータ値として求める。

`perps` メンバー関数:

> `perps` は点から曲線／曲面に下ろした垂線の足のパラメータ値を (複数あればすべて) 求める。

### 曲線と曲線の関係 ###

`closest` メンバー関数:

> `closest` はふたつの曲線の最近傍点となるパラメータ値を求める。

`perps` メンバー関数:

> `perps` は曲線から曲線に下ろした垂線の足の曲線のパラメータ値の対を (複数あればすべて) 求める。

`isect` メンバー関数:

> `isect` は曲線と曲線の交点を (複数あればすべて) 求める。

### 曲線と曲面の関係 ###

`isect` メンバー関数:

> `isect` は曲線と曲面の交点を（複数あればすべて）求める。

`project` メンバー関数:

> 指定方向ベクトルに沿って、または面の normal となるよう、曲線を曲面上に投影した、面上の曲線を求める。

### 曲面と曲面の関係 ###

`isect` メンバー関数:

> `isect` は曲面と曲面の交線を (複数あればすべて) 求める。

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-surface.png](http://mgcl.googlecode.com/svn/wiki/image/mg-surface.png)

## MGCurve ##

曲線全般を表現する抽象クラス。
サブクラスに `MGStraight`, `MGEllipse`, `MGLBRep`, `MGRLBRep`,
`MGTrimmedCurve`, `MGCompositeCurve` がある。

![http://mgcl.googlecode.com/svn/wiki/image/mg-curve.png](http://mgcl.googlecode.com/svn/wiki/image/mg-curve.png)

以下の関数が定義されている。

  * あるパラメータ値における n 次微分値、方向ベクトル、曲率の計算 (評価)。
  * 始終点のパラメータ値および、座標値の計算。
  * ボックス枠の計算。
  * 点が曲線に乗っているかどうか試験し、そのパラメータ値を求める。
  * ある点からの最近傍点、曲線同士の最近傍点のパラメータ値の組を求める。
  * 線積分の計算 (線で囲まれる面の面積を求める)。
  * 曲線状の 2 点間の曲線の長さの計算。
  * 曲線のある点から曲線に沿って、ある距離はなれた点のパラメータ値の計算。
  * 曲線、曲面との交線計算。
  * 曲線の方向の逆転。
  * 曲線の各種座標変換。
  * 二つの曲線の同一性判定。
  * オフセット曲線の計算。
  * 二つの曲線の内接円の計算。
  * 曲面にパラメータ範囲の制限を加える、制限を取り去る。
  * 曲線のスウィープ面を求める。
  * 曲線をある面に投影した曲線を求める。

> ![http://mgcl.googlecode.com/svn/wiki/image/three-dimensional-curve.png](http://mgcl.googlecode.com/svn/wiki/image/three-dimensional-curve.png)

### スプライン曲線クラス ###

スプライン曲線を

  * オーダー k (次数 k-1),
  * B 表現次元 n,
  * ノットベクトル t,
  * B 係数 P

で、`MGRLBRep` の場合はさらに

  * P の各点に対応した重み係数

を加えて表現します。

`MGLBRep` (非 Rational な線 B 表現):

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-lbrep.png](http://mgcl.googlecode.com/svn/wiki/image/mg-lbrep.png)

> k=2 のときスプライン曲線は折れ線 (polyline) であり、
> 最初の点のパラメータ値を 0.0 として点 id をその点のパラメータ値とする折れ線スプラインが利用可能です。

`MGRLBRep` (Rational な線 B 表現):

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-rlbrep.png](http://mgcl.googlecode.com/svn/wiki/image/mg-rlbrep.png)

`MGPPRep` (多項式表現):

> `MGPPRep` は `MGCurve` の、と言うよりは `MGGeometry` のサブクラスではありません。

主な機能

  * 位置データのみから曲線を求める。(補間によるスプライン曲線の計算)
  * データポイント、ノットベクトル、位置データから曲線を求める。
  * データポイントと接続条件 (1 次または 2 次微分値) を与えて曲線を求める。
  * 折れ線と折れ線に内接する円弧データを含む自由曲線を求める。
  * 楕円を曲線で近似する。
  * 二つの 2 次元の曲線を混合して 3 次元曲線を求める。
  * 最小二乗法で曲線を求める。
  * Schoenberg and Reunsch のスムージング関数により曲線を求める。
  * オリジナルと異なるノットコンフィギュレーションで元の曲線を近似する。
  * PP 表現を B 表現に変換する。
  * ノットを挿入する。
  * 誤差範囲内で冗長なノットを削除する。
  * 二つの異なる表現の曲線を接続してひとつの B 表現とする。
  * 曲線の一部のみを取り出して新しい B 表現とする。
  * 方向を逆転、またはパラメータ範囲を変更する。
  * オーダーの変更をする(高次元曲線への変換)。
  * n 次微分値を求める(左右の連続性を指定可能)。
  * 曲線の曲率連続な延長をする。
  * ある点から曲線におろした垂点を求める。
  * 二つの曲線または曲線と曲面とのお互いに垂直関係にある点の対を求める。
  * 曲線がある平面に乗っているかどうかを判定する。

### その他の曲線クラス ###

`MGTrimmedCurve` (部分曲線):

> 他の `MGCurve` のサブクラスの曲線の 1 部分 (元のパラメータ範囲の 1 部分) を表現する。

`MGSurfCurve` (面上線):

> サーフェスとサーフェスのパラメータ曲線の合成関数。

`MGCompositeCurve` (複合曲線):

> 複数の異なる種類の曲線 (`MGCurve`) を結合してひとつの曲線を表現する。

## MGSurface ##

曲面全般を表現する抽象クラス。以下のサブクラスがあります。

  * `MGPlane` (無限平面)

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-plane.png](http://mgcl.googlecode.com/svn/wiki/image/mg-plane.png)

  * `MGCylinder` (円筒面)
  * `MGSphere` (球面)
  * `MGSBRep` (非 Rational な面 B 表現)
  * `MGRSBRep` (Rational な面 B 表現)

以下の共通の関数を提供します

  * あるパラメータ値 (u, v) における偏微分値を求める (評価)。
  * 曲面の曲率(平均、ガウス、最小、最大)、曲面の第 1、第 2 基本量の計算。
  * ボックス枠の計算。
  * ある点からの最近傍点を求める。
  * 点が面内に乗っているかを判定し、乗っていればそのパラメータ値を求める。
  * 曲面が平面内にあるかどうか判定する。
  * パラメータ u, v を入れ替える。
  * u または v 方向に方向を逆転させる。
  * 面と線、面と面の交点、交線計算をする。
  * ある点から面に降ろした垂点をすべて求める。
  * 曲面の各種座標変換。
  * オフセット曲面を求める。

### 面 B 表現クラス ###

`MGSBRep` はテンソル積の考えにより `MGLBRep` (線 B 表現) を曲面に拡張したものであり、
`MGRSBRep` は `MGRLBRep` を曲面に拡張したものです。

`MGSBRep` (面 B 表現):

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-sbrep.png](http://mgcl.googlecode.com/svn/wiki/image/mg-sbrep.png)

`MGRSBRep` (Rational な面 B 表現):

> ![http://mgcl.googlecode.com/svn/wiki/image/mg-rsbrep.png](http://mgcl.googlecode.com/svn/wiki/image/mg-rsbrep.png)

`MGSBRep`, `MGRSBRep` の機能：

  * 格子状の位置データから曲面を求める (補間により曲面の生成)。
  * 格子状のデータポイント、ノットベクトル、位置データから曲面を求める。
  * 格子状のデータポイントと接続条件 (接平面、ツイストデータなど)を与えて曲面を求める。
  * 格子状のデータポイント、ノットベクトルと端末条件 (ツイストデータなど) から曲面を求める。
  * 最小二乗法で曲面を求める。
  * Schoenberg and Reinsch のスムージング関数により曲面を求める。
  * オリジナルと異なるノットコンフギュレーションで元の曲面を近似する。
  * ノットを挿入する。
  * 二つの異なる表現の曲面を接続して一つの面 B 表現とする。
  * 曲面の一部のみを取り出して新しい B 表現とする。
  * 始終点のパラメータ値、または座標値を求める。
  * ある点における法線を求める。
  * パラメータラインを求める。
  * 縁となるパラメータラインを求める。
  * 曲面の曲率連続な延長をする。
  * u と v とを交換した面 B 表現を求める。
  * 曲面に一部変形を加える。