unit gettablefromfile;
interface
uses crt;
	const n = 12; p = 5;
	type
		struct = array[1..p] of integer;
		arr    = array[1..n] of struct;
	
	
	procedure prepareArray(filename: string; var A : arr);
	procedure readfileline(str: string; var struct : struct);
	procedure writeArray(A:arr);
implementation


	procedure readfileline(str: string; var struct : struct);
	var istr, istruct, len :integer;
	Begin
	istruct := 1;
	len := length(str);
	for istr := 1 to len do
		if str[istr] = ',' 
		then istruct := istruct + 1
		else if ((ord(str[istr]) >= 48) and (ord(str[istr]) <= 57))
			 then struct[istruct] := struct[istruct]*10 + (ord(str[istr])-48);
	End;



	procedure prepareArray(filename: string; var A : arr);
	var i : integer;
		f : text;
		s : string;
	begin
	assign(f,filename);
	reset(f);
	i := 1;
	while not eof(f) do
		begin
		readln(f,s);
		readfileline(s,A[i]);
		i := i + 1;
		end;
	end;
	
	
	procedure writeArray(A:arr);
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
