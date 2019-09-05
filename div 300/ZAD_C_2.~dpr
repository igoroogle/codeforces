program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
    a,b:array [0..1000100] of int64;
    n,m,a1,a2,mx,d:int64;
    i: integer;
begin
    readln(n, m);
    for i := 1 to m do read(a[i],b[i]);
    mx := 0;
    a[0]:=0;
    b[0]:=0;
    for i := 0 to m-1 do
    begin
        a1 := a[i+1]-a[i];
        a2 := abs(b[i]-b[i+1]);
        if (a1<a2) then
        begin
            writeln('IMPOSSIBLE');
            readln;
            halt;
        end;
        d:=max(b[i],b[i+1])+(a1-a2) div 2;
        if (d>mx) then mx := d;
    end;
    d := (n-a[m])+b[m-1];
    if (d>mx) then mx := d;
    writeln(mx);
    readln;
end.
