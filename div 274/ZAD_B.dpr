program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 10010;
var
   x,y:array [1..1010] of integer;
   sh:array [0..dl,0..100] of integer;
   n,k,xt,kol,min,max,a1,b1,i:integer;
begin
   readln(n,k);
   for i:=0 to dl do sh[i,0]:=0;
   for i:=1 to n do
      begin
         read(xt);
         inc(sh[xt,0]);
         sh[xt,sh[xt,0]]:=i;
      end;
   readln;
   kol:=0;
   min:=1;
   max:=dl;
   while kol<k do
      begin
         while sh[min,0]=0 do inc(min);
         while sh[max,0]=0 do dec(max);
         if (min=max) or (min+1=max) then break;
         inc(kol);
         a1:=sh[max,sh[max,0]];
         b1:=sh[min,sh[min,0]];
         x[kol]:=a1;
         y[kol]:=b1;
         dec(sh[max,0]);
         dec(sh[min,0]);
         inc(sh[max-1,0]);
         sh[max-1,sh[max-1,0]]:=a1;
         inc(sh[min+1,0]);
         sh[min+1,sh[min+1,0]]:=b1;
         dec(min);
         inc(max);
      end;
    min:=1;
    max:=dl;
    while sh[min,0]=0 do inc(min);
    while sh[max,0]=0 do dec(max);   
   writeln(max-min,' ',kol);
   for i:=1 to kol do writeln(x[i],' ',y[i]);
   readln;
end.
