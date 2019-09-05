program Project;

{$APPTYPE CONSOLE}

uses
  SysUtils, math;


var
  a:array[1..410, 1..410] of integer;
  i,j,p,w,n,m:integer;
  q :int64;
  ch :char;
begin
    readln(n,m);
    for i:=1 to 410 do
        for j:=1 to 410 do
            a[i,j] := 100000;
    for i:=1 to 410 do
        a[i,i] := 0;
    for i:=1 to n do
    begin
        if (i=n) then readln(ch)
        else read(ch);
        if (ch='>') then
        begin
            for j:=1 to m-1 do
            begin
                if (i=1) then
                    a[j,j+1]:=0;
                if (i>1) then
                    a[j+((i-1)*m)][j+1+((i-1)*m)]:=0;
            end;
            continue;
        end;

      if (ch ='<') then
        begin
            for j:=2 to m do
            begin
                if (i = 1) then
                    a[j][j - 1] := 0;
                if (i > 1) then
                    a[j + ((i - 1) * m)][j - 1 + ((i - 1) * m)] := 0;
            end;
        end;

    end;
    for j:=1 to m do
    begin
        if (j = m) then
            readln(ch)
        else
        read(ch);

       if (ch = 'v') then
        begin
            for i := 1 to n - 1 do
            begin
                    a[j + ((i - 1) * m)][j + (i * m)] := 0;
            end;
        end;

        if (ch = '^') then
        begin
            for i := n downto 2 do
            begin
                    a[j + ((i - 1) * m)][j + ((i - 2) * m)] := 0;
            end;
        end;

    end;





    w := n * m;

    for p := 1 to w do
        for i := 1 to w do
            for j := 1 to w do
                if (a[i][p] < 90000) and (a[p][j] < 90000) then
                    a[i][j] := min(a[i][j], a[i][p] + a[p][j]);



    q := 0;
    for i := 1 to n * m do
         for j := 1 to n * m do
             if (a[i][j] > 90000) then
                 inc(q);

    if (q = 0) then
        writeln('YES')
    else
        writeln('NO');    
    readln;
    readln;
end.
