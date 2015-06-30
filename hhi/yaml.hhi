<?hh // decl /* -*- php -*- */
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the 'hack' directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

const int YAML_ANY_SCALAR_STYLE = 0;
const int YAML_PLAIN_SCALAR_STYLE = 0;
const int YAML_SINGLE_QUOTED_SCALAR_STYLE = 0;
const int YAML_DOUBLE_QUOTED_SCALAR_STYLE = 0;
const int YAML_LITERAL_SCALAR_STYLE = 0;
const int YAML_FOLDED_SCALAR_STYLE = 0;
const int YAML_ANY_ENCODING = 0;
const int YAML_UTF8_ENCODING = 0;
const int YAML_UTF16LE_ENCODING = 0;
const int YAML_UTF16BE_ENCODING = 0;
const int YAML_ANY_BREAK = 0;
const int YAML_CR_BREAK = 0;
const int YAML_LN_BREAK = 0;
const int YAML_CRLN_BREAK = 0;
const string YAML_NULL_TAG = 'tag:yaml.org,2002:null';
const string YAML_BOOL_TAG = 'tag:yaml.org,2002:bool';
const string YAML_STR_TAG = 'tag:yaml.org,2002:str';
const string YAML_INT_TAG = 'tag:yaml.org,2002:int';
const string YAML_FLOAT_TAG = 'tag:yaml.org,2002:float';
const string YAML_TIMESTAMP_TAG = 'tag:yaml.org,2002:timestamp';
const string YAML_SEQ_TAG = 'tag:yaml.org,2002:seq';
const string YAML_MAP_TAG = 'tag:yaml.org,2002:map';
const string YAML_PHP_TAG = '!php/object';

function yaml_emit_file($filename, $data, $encoding, $linebreak = null, array $callbacks = []);
function yaml_emit($data, $encoding, $linebreak = null, array $callbacks = []);
function yaml_parse_file($filename, $pos = 0, &$ndocs = null, array $callbacks = []);
function yaml_parse_url($url, $pos = 0, &$ndocs = null, array $callbacks = []);
function yaml_parse($input, $pos = 0, &$ndocs = null, array $callbacks = []);
