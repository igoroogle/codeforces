program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   c,w,k:array [1..1010] of integer;
   use:array [1..1010] of boolean;
   n,m,i,j,kol,ww,p,dd:integer;
begin
   read(n,m);
   for i:=1 to 1010 do use[i]:=true;
   for i:=1 to n do read(w[i]);
   for i:=1 to m do read(c[i]);
   kol:=0;
   for i:=1 to m do
      if (use[c[i]]) then
         begin
            inc(kol);
            k[kol]:=c[i];
            use[c[i]]:=false;
         end;
   ww:=0;
   for i:=1 to m do
      begin
         p:=1;
         for j:=1 to kol do
            if (k[j]=c[i]) then
               begin
                  p:=j;
                  break;
               end;
         for j:=p-1 downto 1 do
            begin
               ww:=ww+w[k[j-1]];
               dd:=k[j-1];
               k[j-1]:=k[j];
               k[j]:=dd;
            end;
      end;
   writeln(ww);
   readln;
   readln;
end.
