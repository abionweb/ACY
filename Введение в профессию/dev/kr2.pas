program kr2;

uses crt, gettablefromfile;
const p = 5;
type
	arr = array[1..1000, 1..p] of integer;
	result = array[1..1000] of record
		subunit, count : integer;
	end;
	
var i, n : integer; 
	A : arr;
	B : result;
	

procedure searchSubunit(subunit:integer);
var i : integer = 0;
begin
	repeat
		i:=i+1;
		if B[i].subunit = subunit then B[i].count := B[i].count + 1;
		if B[i].subunit = 0 then begin 
			B[i].subunit := subunit; 
			B[i].count:= 1; 
		end;
	until B[i].subunit = subunit;
end;

procedure printResult;
begin
	writeln('Всего детей: ', n);
	i := 1;
	repeat
	writeln('Подразделение ', B[i].subunit, ': ', B[i].count, ' детей');
	i := i + 1;
	until B[i].subunit = 0;
end;

BEGIN
clrscr;

write('Введите количество строк в таблице: ');
readln(n);

prepareArray('table.csv', A);

printArray(A);

for i := 1 to n do searchSubunit(A[i,1]); //перебираем массив

printResult;
END.
