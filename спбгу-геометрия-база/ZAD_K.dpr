program ZAD_K;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a1,b1,c1,a2,b2,c2,x,y,z:extended;
begin
   reset(input,'intersec1.in');
   rewrite(output,'intersec1.out');
   readln(a1,b1,c1,a2,b2,c2);
   z:=a1*b2-a2*b1;
   x:=(b1*c2-b2*c1)/z;
   y:=(c1*a2-c2*a1)/z;
   writeln(x,' ',y);
end.
