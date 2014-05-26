# primeFactorization.rb #
include(Math)

# 引数: 整数x
# 返値: xの素因数
# 機能: 引数の素因数を表示する関数
def factorizeNumber(x)
	if x == 1 # 引数が1だったらそのまま返す
		print("1\n")
	else # 引数が1以外の場合
		j = 2 # 除算判別子
		while j <= sqrt(x) && x != 1 do
			if x % j == 0 # xがjで割りきれる場合
				print(j, "\n") # 素因数を表示する
				x = x / j # 素因数で割って次の処理へ
			else # xがjで割り切れない場合
				j = j + 1
			end
		end
        if x != 1
            print(x, "\n") # 余りを表示
        end
	end
	print("End\n")
end