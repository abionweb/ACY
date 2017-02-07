unit gettablefromfile;
interface
uses crt;
	const n = 12; p = 5;
	type
		struct = array[1..p] of integer;
		arr    = array[1..1000] of struct;
	
	
	procedure prepareArray(filename: string; var A : arr);
	procedure readFileLine(str: string; var struct : struct);
	procedure printArray(A:arr);
implementation


	procedure readFileLine(str: string; var struct : struct);
	var istr, len : integer;
		istruct :integer = 1;
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
		
		
end.
