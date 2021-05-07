#define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER
#include <catch2/catch.hpp>
#include <sstream>
#include "adm/document.hpp"
#include "adm/elements/audio_object.hpp"
#include "adm/parse.hpp"
#include "adm/errors.hpp"

TEST_CASE("xml_parser/audio_programme_label") {
  using namespace adm;
  auto document = parseXml("xml_parser/labels.xml");
  auto audioProgramme = document->lookup(parseAudioProgrammeId("APR_1001"));

  auto labels = audioProgramme->getElements<AudioProgrammeLabel>();
  REQUIRE(labels.size() == 7);

  REQUIRE(labels[0].has<LabelLanguage>() == true);
  REQUIRE(labels[0].get<LabelLanguage>() == "en");
  REQUIRE(labels[0].has<LabelValue>() == true);
  REQUIRE(labels[0].get<LabelValue>() == "My Programme");

  REQUIRE(labels[1].has<LabelLanguage>() == true);
  REQUIRE(labels[1].get<LabelLanguage>() == "deu");
  REQUIRE(labels[1].has<LabelValue>() == true);
  REQUIRE(labels[1].get<LabelValue>() == "Mein Programm");

  REQUIRE(labels[2].has<LabelLanguage>() == true);
  REQUIRE(labels[2].get<LabelLanguage>() == "fr");
  REQUIRE(labels[2].has<LabelValue>() == false);

  REQUIRE(labels[3].has<LabelLanguage>() == true);
  REQUIRE(labels[3].get<LabelLanguage>() == "es");
  REQUIRE(labels[3].has<LabelValue>() == false);

  REQUIRE(labels[4].has<LabelLanguage>() == false);
  REQUIRE(labels[4].has<LabelValue>() == true);
  REQUIRE(labels[4].get<LabelValue>() == "Undefined Language");

  REQUIRE(labels[5].has<LabelLanguage>() == false);
  REQUIRE(labels[5].has<LabelValue>() == false);

  REQUIRE(labels[6].has<LabelLanguage>() == false);
  REQUIRE(labels[6].has<LabelValue>() == false);
}

TEST_CASE("xml_parser/audio_content_label") {
    using namespace adm;
    auto document = parseXml("xml_parser/labels.xml");
    auto audioContent = document->lookup(parseAudioContentId("ACO_1001"));

    auto labels = audioContent->getElements<AudioContentLabel>();
    REQUIRE(labels.size() == 7);

    REQUIRE(labels[0].has<LabelLanguage>() == true);
    REQUIRE(labels[0].get<LabelLanguage>() == "en");
    REQUIRE(labels[0].has<LabelValue>() == true);
    REQUIRE(labels[0].get<LabelValue>() == "My Content");

    REQUIRE(labels[1].has<LabelLanguage>() == true);
    REQUIRE(labels[1].get<LabelLanguage>() == "deu");
    REQUIRE(labels[1].has<LabelValue>() == true);
    REQUIRE(labels[1].get<LabelValue>() == "Mein Inhalt");

    REQUIRE(labels[2].has<LabelLanguage>() == true);
    REQUIRE(labels[2].get<LabelLanguage>() == "fr");
    REQUIRE(labels[2].has<LabelValue>() == false);

    REQUIRE(labels[3].has<LabelLanguage>() == true);
    REQUIRE(labels[3].get<LabelLanguage>() == "es");
    REQUIRE(labels[3].has<LabelValue>() == false);

    REQUIRE(labels[4].has<LabelLanguage>() == false);
    REQUIRE(labels[4].has<LabelValue>() == true);
    REQUIRE(labels[4].get<LabelValue>() == "Undefined Language");

    REQUIRE(labels[5].has<LabelLanguage>() == false);
    REQUIRE(labels[5].has<LabelValue>() == false);

    REQUIRE(labels[6].has<LabelLanguage>() == false);
    REQUIRE(labels[6].has<LabelValue>() == false);
}

TEST_CASE("xml_parser/audio_object_label") {
    using namespace adm;
    auto document = parseXml("xml_parser/labels.xml");
    auto audioObject = document->lookup(parseAudioObjectId("AO_1001"));

    auto labels = audioObject->getElements<AudioObjectLabel>();
    REQUIRE(labels.size() == 7);

    REQUIRE(labels[0].has<LabelLanguage>() == true);
    REQUIRE(labels[0].get<LabelLanguage>() == "en");
    REQUIRE(labels[0].has<LabelValue>() == true);
    REQUIRE(labels[0].get<LabelValue>() == "My Object");

    REQUIRE(labels[1].has<LabelLanguage>() == true);
    REQUIRE(labels[1].get<LabelLanguage>() == "deu");
    REQUIRE(labels[1].has<LabelValue>() == true);
    REQUIRE(labels[1].get<LabelValue>() == "Mein Objekt");

    REQUIRE(labels[2].has<LabelLanguage>() == true);
    REQUIRE(labels[2].get<LabelLanguage>() == "fr");
    REQUIRE(labels[2].has<LabelValue>() == false);

    REQUIRE(labels[3].has<LabelLanguage>() == true);
    REQUIRE(labels[3].get<LabelLanguage>() == "es");
    REQUIRE(labels[3].has<LabelValue>() == false);

    REQUIRE(labels[4].has<LabelLanguage>() == false);
    REQUIRE(labels[4].has<LabelValue>() == true);
    REQUIRE(labels[4].get<LabelValue>() == "Undefined Language");

    REQUIRE(labels[5].has<LabelLanguage>() == false);
    REQUIRE(labels[5].has<LabelValue>() == false);

    REQUIRE(labels[6].has<LabelLanguage>() == false);
    REQUIRE(labels[6].has<LabelValue>() == false);
}