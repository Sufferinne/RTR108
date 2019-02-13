<Qucs Schematic 0.0.15>
<Properties>
  <View=0,0,800,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=02.dat>
  <DataDisplay=02.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 150 290 0 0 0 0>
  <GND * 1 410 300 0 0 0 0>
  <Vdc V1 1 150 220 18 -26 0 1 "36.8 V" 1>
  <R R1 1 290 140 -26 15 0 0 "7 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.DC DC1 1 220 310 0 36 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <R R2 1 410 200 15 -26 0 1 "x" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.SW SW1 1 530 120 0 58 0 0 "DC1" 1 "lin" 1 "x" 1 "5 Ohm" 1 "50 Ohm" 1 "10" 1>
</Components>
<Wires>
  <150 250 150 290 "" 0 0 0 "">
  <410 140 410 170 "" 0 0 0 "">
  <150 140 260 140 "" 0 0 0 "">
  <150 140 150 190 "" 0 0 0 "">
  <410 230 410 300 "" 0 0 0 "">
  <320 140 410 140 "izeja" 420 110 71 "0">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
