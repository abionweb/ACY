program kr2;

uses crt;
const p = 5;
type
	arrStruct = array[1..p] of integer;
	arr = array[1..1000] of arrStruct;
	result = array[1..1000] of record
		subunit, count : integer;
	end;
	
	
var i, n : integer; 
	A : arr;
	B : result;


procedure readFileLine(str: string; var struct : arrStruct);
var istr, len : integer;
	istruct : integer = 1;
Begin
	len := length(str);
	for istr := 1 to len do
		case str[istr] of
			',': istruct := istruct + 1;
			'0'..'9': struct[istruct] := struct[istruct]*10 + (ord(str[istr])-48);
		end;
End;


procedure prepareArray(filename: string; var A : arr);
var i : integer = 1;
	f : text;
	s : string;
begin
	assign(f,filename);
	reset(f);
	while not eof(f) do
		begin
		readln(f,s);
		readFileLine(s,A[i]);
		i := i + 1;
		end;
end;
	
	
procedure printArray(A:arr);
var i,j : integer;
begin
	for i := 1 to n do
		begin
		for j := 1 to p do
			begin
			write (A[i,j]:10);
			end;
		writeln;
		end;
	readln;
end;

procedure searchSubunit(subunit:integer);
var u : integer = 0;
begin
	repeat
		u:=u+1;
		if B[u].subunit = subunit then B[u].count := B[u].count + 1;
		if B[u].subunit = 0 then begin 
			B[u].subunit := subunit; 
			B[u].count:= 1; 
		end;
	until B[u].subunit = subunit;
end;

procedure printResult;
var i : integer = 1;
begin
	writeln('Всего детей: ', n);
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
