g++ -o gen gen.cpp
g++ -o sol sol.cpp
for ((i = 1; ; ++i)) do
	echo $i
	./gen $i > int
	./ea < int > out1
	./sol < int > out2
	diff -w out1 out2 || break
	diff -w <(./ea < int) <(./sol < int ) || break
done
