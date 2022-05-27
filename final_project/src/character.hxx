//
// Created by thebr on 5/26/2022.
//
#pragma once

#include <ge211.hxx>


/// We will represent positions as GE211 `Posn<float>`s, which we alias
/// with the type name `Position`. This is a struct that could be
/// defined like so:
///
///   struct Position
///   {
///       float x;   // pixel distance from left edge of window
///       float y;   // pixel distance from top edge of window
///   };
using Position = ge211::Posn<float>;


class Character
{
public:

    /// Constructs a new character. It needs to know where to position this
    /// character (could be either ghost or pacman)
    ///
    /// In addition to constructing the character in the model in the first
    /// place, this can also be used to reset the character by creating a new
    /// character to assign over it:
    ///
    ///     character = Character();
    ///
    Character(); //TODO add initiation position to character constructor

    /// Returns the position of the top-left corner of the ball's
    /// "bounding box", meaning the smallest rectangle in which is can
    /// be enclosed. This is useful to the UI because sprites are
    /// positioned based on their top-left corners.
    Position top_left() const;


    /// Returns the state of the character after `dt` seconds have passed,
    /// were it to move freely (without obstacles). Thus, the result is
    /// a new character just like this one but whose position has been
    /// updated based on its current velocity and the given time
    /// interval `dt`. (This is an application of the equation relating
    /// distance to velocity and time: *Δd = v ⋅ Δt*.)
    ///
    /// This function is useful because the model's algorithm for
    /// collision detection involves speculatively moving the character and
    /// checking where it would end up, before actually moving it.
    ///
    /// This can also be used to actually move it, via assignment:
    ///
    ///    character = character.next();
    ///
    Character next(double dt);

private:
    float speed;


};
