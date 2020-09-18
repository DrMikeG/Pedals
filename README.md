# Pedals

conversation:

- General
- Bach and piano

- Electric piano (Dad was a vicar - church organ)
- Foot pedals and midi

- Organ pedals.

Fotdella

12 pedals.

On/off
Force / impulse to determine volume (optional)

Plugs into keyboard.

Untransposed note?


- Recording
- Bass

- Roland VR-09B Combo

Pedalboard: PK-9

AC adaptor Via PK cable



MP-113
Width: 54 cm / 21,3"
Depth: 42 cm / 16,5"
Height: 14 cm / 5,5"


https://www.thomann.de/gb/doepfer_mbp25_electronic_with_1_pedal.htm

dimension of one bass pedal: about 530 mm (length) x 380 mm (depth) x 95 mm (height)



480

446 + 1 space

10 white keys
7 black keys
2 gaps

19 key
18 gaps

# Project Update 18th September #

I'm making this because I have a friend who is interested in trying to play it - but not interested enough to pay £500 to try playing it.
And I've really been enjoying this project.

I don't usually do work in progress videos, but this project has been going over a month now, and I felt I had learned enough to warrant a quick recap.

I'm attempting to build - from scratch, a set of 13 midi organ-style pedals.

It will be mostly 3d printed, and I'm using magnets and hall effects sensors.

I'm using the hugely powerful Teensie 4.0 as the midi controller, and that has 14 analog inputs, which greatly simplifies the build.

Power requirements.
I had a KY-024 linear hall effect breakout board in my parts bin so I started designing around that, rather than the raw sensor.
It has useful features, such as a power LED and an onboard comparator so it can return either an analog or digital reading, with a trim pot to adjust the digital sensitivity.
Now I plan on going analog, because I plan on measuring key velocity, but being able to use the build in LEDs for power and signal is really appealing for debugging the build.

The power draw of the board was a concern, because the Teensie is limited to 250ma (which itself is impressive for a microcontroller regulator) - but had literally no idea what the 13 KY-024 dev boards might draw.
Measuring it, I came out with 6.5mA - which sounded much too low for two bright (althought small) LED - but having sought some advice from the PJRC forum, it seems that is resonable, and I can power all 13 boards direct from the teensie.

I aiming to keep the BOM low, so I'm trying to use commodity parts. When you start to multply everything by even just 13 - things start to get expensive.

Designing the keys.

My key design is a simple pivot. I considered levers and gears, but discussing that with the my friend who has experience with organ pedals, they don't tend to have much simpler mechanics than piano keys.

Springs are expensive - and to start with I wanted large compass springs like many organ pedals used. I made a rig to bend coat hanger wire into springs.
That worked surprisingly well, although with a double coil the springs were much two powerful, and with only a single coil they tended to bend plastically not elastically.

So I trawled ebay for cheap springs and found 20 tension springs for £6. So I splashed out.
It turns out that 15mm springs are very small, but strong enough for my purpose.
But it required a major key re-design to make a level long enough for the spring travel.

Making a full size cardboard mock of the keyboard taught me lots of things.

Firsty, the keys are tightly packed. I mean, really tight. The width of keyboard I wanted was just wide enough for the dev boards.
Which is helpful because it means I can design sharp and natural keys with the same mechanism, not having to design neighbouring keys with an offset.

It turns out that although the distance moved

