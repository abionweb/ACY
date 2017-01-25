program kr2;

uses crt, gettablefromfile;
const n = 12; p = 5;
type
	//struct = array[1..p] of integer;
	arr    = array[1..n, 1..p] of integer;
	result = array of record
		subunit, count : integer;
	end;
	
var i, j : integer;
	A : arr;
	B : result;
	y : boolean;

BEGIN
clrscr;
SetLength(B,0);

prepareArray('table.csv', A);
writeArray(A);

for i := 1 to n do begin //перебираем массив
	y := true;

	
	{Ищем подразделение в массиве результатов}
	for j := 0 to length(B)-1 do begin
		if B[j].subunit = A[i,1] then begin
			B[j].count := B[j].count + 1;
			y := false;
		end;
	end;
	
	
	
	{Если подразделение в массиве с результатами не обнаружено, добавляем его}
	if y then begin 
		SetLength(B,length(B)+1);
		B[length(B)-1].subunit := A[i,1];
		B[length(B)-1].count   := 1;
	end;
	
	
end;


{Вывод результатов}
writeln('Всего детей: ', n);
for j := 0 to length(B)-1 do writeln('Подразделение ', B[j].subunit, ': ', B[j].count, ' детей');

{Освобождение памяти}
B := nil;
END.
