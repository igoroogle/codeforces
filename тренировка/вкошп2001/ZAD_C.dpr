program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,c,d:array [1..6] of string;
   b:array [0..9,1..6] of string;
   i,j,h,m,x,y,k:integer;
   f:boolean;
begin
    reset(input,'input.txt');
    assign(output,'output.txt');
    a[1]:='..##.....#..##..####.#..#.####..###.####..##...##.';
    a[2]:='.#..#...##.#..#....#.#..#.#....#.......#.#..#.#..#';
    a[3]:='.#..#..#.#....#...#..#..#.###..###....#...##..#..#';
    a[4]:='.#..#....#...#.....#.####....#.#..#..#...#..#..###';
    a[5]:='.#..#....#..#......#....#.#..#.#..#..#...#..#....#';
    a[6]:='..##.....#.####.###.....#..##...##...#....##..###.';
    for i:=1 to 6 do readln(c[i]);
    for i:=0 to 9 do
       for j:=1 to 6 do b[i,j]:=copy(a[j],i*5+1,5);
    {for i:=0 to 9 do
       begin
          for j:=1 to 6 do writeln(b[i,j]);
          writeln;
          writeln;
       end;}
    k:=0;
    h:=0;
    m:=0;
    for x:=0 to 23 do
       for y:=0 to 59 do
          begin
             for i:=1 to 6 do d[i]:=b[x div 10 mod 10,i]+b[x mod 10,i]+b[y div 10 mod 10,i]+b[y mod 10,i];
             f:=true;
             for i:=1 to 6 do
                for j:=1 to 20 do
                   if (c[i][j]='#') and (d[i][j]<>'#') then
                      begin
                         f:=false;
                         break;
                      end;
             if (f) then
                begin
                   inc(k);
                   h:=x;
                   m:=y;
                end;
          end;
    if (k=0) then writeln('ERROR')
    else if (k>1) then writeln('AMBIGUITY')
    else
       begin
          if (h<10) then write(0);
          write(h,':');
          if (m<10) then write(0);
          writeln(m);
       end;
    readln;
end.
