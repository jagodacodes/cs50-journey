# Recover

## Objective

Recover deleted JPEG images from a forensic memory card image.

## Concepts Practised

- File I/O
- Memory
- Binary files
- Buffers

## What This Program Does

The program scans a forensic image of a memory card, detects the beginning of JPEG files, and reconstructs each image by writing the recovered data into separate JPEG files.

## Files

- `recover.c` – implementation of the JPEG recovery program.
- `card.raw` – forensic memory card image used as input.
- `Makefile` – build configuration.

## What I Learned

This exercise helped me understand how binary files are processed and demonstrated how deleted files can be recovered by recognising file signatures.
